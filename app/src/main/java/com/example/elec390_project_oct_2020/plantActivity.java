package com.example.elec390_project_oct_2020;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.elec390_project_oct_2020.DataBase.DataBaseHelper;
import com.example.elec390_project_oct_2020.Model.Plant;
import com.example.elec390_project_oct_2020.SharedPreference.SharedPreferenceController;

import java.io.ByteArrayOutputStream;
import java.io.InputStream;

public class plantActivity extends AppCompatActivity {
    protected Button deletePlantButton, waterMyPlantButton;
    protected TextView plantActNameTextView, plantActDescriptionTextView,
                        MoistureLevelTextView, NotificationTextView,
                        tempDataTextView, moistureDataTextView;//newly added Nov29th
    protected ImageView plantActImageView;
    private static final String TAG = "plantActivity";
    protected String plantName, plantDescription;
    protected int threshold,thresholdMois, thresholdTemp;//added Nov29th
    private double humidity;
    protected long plantID;
    private int valueofMoisture;
    private int valueofTemperature;//added Nov 29th
    private boolean threadStop;
    static final int PICTURE = 1;//example: requestCode to open gallery

    //int moisture = -1;
    //int temperature = -1;
    //private DataController dataController = null;
    private SharedPreferenceController sharedPreferenceController =null;

    private byte[] img;//not ussing this ...

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //ActionBar actionBar = getSupportActionBar();
        //actionBar.setDisplayHomeAsUpEnabled(true);
        setContentView(R.layout.activity_plant);
        Log.d(TAG, "plantActivity: onCreate() called");
        plantActNameTextView = (TextView) findViewById(R.id.plantActNameTextView);
        plantActDescriptionTextView = (TextView) findViewById(R.id.plantActDescriptionTextView);
        MoistureLevelTextView = (TextView) findViewById(R.id.MoistureLevelTextView);
        NotificationTextView = (TextView) findViewById(R.id.NotificationTextView);
        deletePlantButton = (Button) findViewById(R.id.deletePlantButton);
        waterMyPlantButton = (Button) findViewById((R.id.waterMyPlantButton));
        plantActImageView = (ImageView) findViewById(R.id.plantActImageView);

        //added by yifan Nov 29th
        moistureDataTextView = findViewById(R.id.textViewplantMoisture);
        tempDataTextView = findViewById(R.id.textViewplantTemp);

        Intent intent = getIntent();
        /***TEST***/
        sharedPreferenceController = new SharedPreferenceController(plantActivity.this);

        // not using these lines any more..... yifan
        //String moistureData = sharedPreferenceController.get_MoistureData();
        //Log.d(TAG, "moisture is + "+moistureData);
        //moistureData = getStringValue(moistureData);
        //valueofMoisture = Integer.parseInt(moistureData);

        /***TEST***
        plantName = intent.getStringExtra(getString(R.string.plant_name));
        plantDescription = intent.getStringExtra(getString(R.string.plant_description));
        img = intent.getByteArrayExtra(getString(R.string.plant_image));
        
        plantID = intent.getLongExtra(getString(R.string.plant_id), 0);
        threshold = intent.getIntExtra(getString(R.string.plant_threshold),0);
        Log.d(TAG, "Plant name: " + plantName + "\n" + "PlantID: " + plantID);
       *****/

        //use this instead
        plantID = Long.valueOf(intent.getStringExtra(getString(R.string.plant_id)));
        Plant currentPlant;
        DataBaseHelper dbHelper;
        dbHelper = new DataBaseHelper(this);
        currentPlant = dbHelper.getPlantByID(plantID);
        plantName = currentPlant.getPlantName();
        plantDescription = currentPlant.getPlantDescription();
        threshold = currentPlant.getMoistureLevel();
        humidity = (750-threshold)/8;
        setPlantinfo();


        //added by yifan NOv 29th
        compareDataSet_OnThread();//Nov 30th it is refreshing data in real time

        deletePlantButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                DataBaseHelper dataBaseHelper = new DataBaseHelper(plantActivity.this);
                dataBaseHelper.deletePlant(plantID);
                finish();
            }
        });

        plantActImageView.setClickable(true);
        plantActImageView.setOnClickListener(onClickThumb);
        if (plantActImageView.getBackground() == null) {//use background to detect empty image

            if (dbHelper.getPlantByID(plantID) != null && dbHelper.getPlantByID(plantID).getPlantImg() != null) {//example: prevent null getdata
                byte[] blob = dbHelper.getPlantByID(plantID).getPlantImg(); //example plant at row 1
                Bitmap p = BitmapFactory.decodeByteArray(blob, 0, blob.length);
                Drawable d = new BitmapDrawable(p);
                plantActImageView.setBackground(d); //example: use this to be detected
                plantActImageView.setImageDrawable(d); //example: use this for activity thumbnail
            } else {
                plantActImageView.setImageResource(R.drawable.plant_img);
                Toast toast = Toast.makeText(getApplicationContext(), "default img，select new img!", Toast.LENGTH_SHORT);
                toast.show();
            }
        }//end if

    }

    @Override
    protected void onResume() {
        super.onResume();
        //compareDataSet_OnThread();
    }

    protected void setPlantinfo() {
        //plantActImageView.setImageResource(img);
        plantActNameTextView.setText(plantName);
        plantActDescriptionTextView.setText(plantDescription);
        MoistureLevelTextView.setText("Plant Threshold: " + humidity + " %RH");

    }

    //not using this
    protected void compareData(int threshold, int currentData){
        Log.d(TAG,"Threshold: " + threshold + "CurrentData: " + currentData);
        if(threshold<currentData){
            NotificationTextView.setText("The plant is well watered");
        }else{
            NotificationTextView.setText("Please Water Your plant");
        }
    }

    //made by yifan Nov 29th
    protected void compareDataSet(){
        valueofMoisture = getMoistureSensorData();
        valueofTemperature = getTemperatureSensorData();

        thresholdMois = threshold;
        thresholdTemp = 25;
        if(valueofMoisture > thresholdMois || valueofTemperature > thresholdTemp){

            NotificationTextView.setText("Please Water Your plant");

        }else{
            NotificationTextView.setText("The plant is well watered");
        }
    }

    public void setData(){
        double humidityReal = (750-valueofMoisture)/8;//already calculated on onCreate
        moistureDataTextView.setText(String.valueOf(humidityReal)+" %RH");
        tempDataTextView.setText(String.valueOf(valueofTemperature)+ " C°");
    }

    /********not using this method any more, Nov29th
    public boolean search_For_Threshold(int threshold){
        boolean bool=false;
        if(moistureArray !=null) {
            for (int i = 0; i < moistureArray.length; ++i) {
                if (moistureArray[i] >= threshold) {
                    bool = true;
                } else {
                    bool = false;
                }
            }
        }
        return  bool;//default is false
    }
    ******/
    //sharedpreference should not be instantiated inside function/ yifan
    //change the return to a single int value, easy to compare
    public int getMoistureSensorData() {//modified function to get the minimun moisture data , yifan on Nov 29th
        String moistureData = sharedPreferenceController.get_MoistureData();
        Log.d(TAG, "moisture data is :" +moistureData);
        if(moistureData!=null){
            return Integer.parseInt(moistureData);

        }else{
            return -1;
        }
    }

    public int getTemperatureSensorData() {//modified function to get the minimun moisture data , yifan on Nov 29th
        String temperatureData = sharedPreferenceController.get_TemperatureData();
        Log.d(TAG, "moisture data is :" +temperatureData);
        if(temperatureData!=null){
            return Integer.parseInt(temperatureData);

        }else{
            return -1;
        }
    }

    protected void compareDataSet_OnThread(){
        thresholdMois = threshold;
        thresholdTemp = 20;

        final Handler handle = new Handler();
        threadStop = false;

        final Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while(!Thread.currentThread().isInterrupted() && !threadStop){
                    try{
                        handle.post(new Runnable() {
                            @Override
                            public void run() {
                                compareDataSet();
                                setData();
                            }
                        });
                        Thread.sleep(2500);
                    }catch(RuntimeException | InterruptedException e){
                        threadStop =true;
                    }

                }
            }
        });
        thread.start();
    }

    protected String getStringValue(String text){
    text = text.trim();
    return text;
    }

    private void msg (String s) {
        Toast.makeText(getApplicationContext(), s, Toast.LENGTH_LONG).show();
    }

    private ImageView.OnClickListener onClickThumb = new ImageView.OnClickListener() {//do this when image clicked
        @Override
        public void onClick(View view) {
            Toast toast = Toast.makeText(getApplicationContext(), "Opening Gallery!", Toast.LENGTH_SHORT);
            toast.show();
            //send intent
            Intent intent = new Intent(Intent.ACTION_PICK, android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
            startActivityForResult(intent, PICTURE);
        }
    };  //Test 29/11

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {//receive request code to open gallery
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == PICTURE&& resultCode==RESULT_OK && null !=data) {
            /*****
             final Uri uri = data.getData();
             String[] projection ={MediaStore.Images.Media.DATA};
             Cursor cursor=getContentResolver().query(uri,projection,null,null,null);
             cursor.moveToFirst();

             int columnIndex=cursor.getColumnIndex(projection[0]);
             String path=cursor.getString(columnIndex);
             cursor.close();

             Bitmap selectFile = BitmapFactory.decodeFile(path);
             *****/
            //**************tested
            try {
                final Uri uri = data.getData();
                final InputStream imageStream = getContentResolver().openInputStream(uri);
                final Bitmap selectedImg = BitmapFactory.decodeStream(imageStream);
                Drawable d = new BitmapDrawable(selectedImg);
                //plantActImageView.setBackground(d);//example: current activity's thumbnail background
                plantActImageView.setImageBitmap(selectedImg);
                //To do: convert to byte[] and save to db
                ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
                // Middle parameter is quality, but since PNG is lossless, it doesn't matter
                selectedImg.compress(Bitmap.CompressFormat.PNG, 0, outputStream);
                byte[] bitmapData= outputStream.toByteArray();
                DataBaseHelper dbHelper;
                dbHelper = new DataBaseHelper(this);
                //test this, this should never be reached before row ID exists
                dbHelper.updateImageByPlantID(plantID,bitmapData);//example: replace blob column at ID
            } catch ( Exception e) {
                e.printStackTrace();
            }
            //*************/



            //https://stackoverflow.com/questions/28870974/pick-image-from-gallery-and-display-in-imagae-view
            //https://stackoverflow.com/questions/10977584/how-to-store-image-in-sqlite-database-from-gallery
            //https://stackoverflow.com/questions/11790104/how-to-storebitmap-image-and-retrieve-image-from-sqlite-database-in-android


        }
    }

}

