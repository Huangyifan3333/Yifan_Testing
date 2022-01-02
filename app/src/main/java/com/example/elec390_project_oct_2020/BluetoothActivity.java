package com.example.elec390_project_oct_2020;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Bundle;

//import android.support.v7.app.AppCompatActivity;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.widget.Toolbar;

import com.example.elec390_project_oct_2020.DataController.DataController;
import com.example.elec390_project_oct_2020.Fragment.BluetoothPairFragment;
import com.example.elec390_project_oct_2020.SharedPreference.SharedPreferenceController;

import java.io.IOException;
import java.io.InputStream;
import java.io.InterruptedIOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Set;
import java.util.UUID;
import java.util.concurrent.TimeUnit;

public class BluetoothActivity extends AppCompatActivity {

private static final String TAG = "BluetoothActivity";

    protected Toolbar toolbarBluetooth = null;
    protected TextView textViewMoisture1 = null;
    protected TextView textViewMoisture2 = null;
    protected TextView textViewTemperature1 = null;
    protected TextView textViewTemperature2 = null;
    protected Button buttonPair = null;//test
    protected Button buttonTime1 = null;
    protected Button buttonTime2 = null;
    protected Button buttonTime3 = null;
    protected Button buttonTime4 = null;
    protected Button buttonStop = null;
    protected Button buttonDisconnect = null;
    protected Button buttonListenTest = null;


    private BluetoothAdapter bluetoothAdapter = null;
    private Set<BluetoothDevice> pairedDevices;
    private ArrayList<String> deviceList = new ArrayList<>();
    private BluetoothSocket bluetoothSocket =null;
    private boolean isBTConnected = false;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private SharedPreferenceController sharedPreferenceController =null;

    private InputStream inputStream;
    private OutputStream outputStream;
    private Boolean stopThread;
    //private String moistureValue = null;
    //private String temperatureValue = null;

    private ArrayList<String> moistureValue = new ArrayList<>();
    private ArrayList<String> tempValue = new ArrayList<>();
    private String data =null;
    private DataController dataController;

    public static final int MESSAGE_READ = 0;
    public static final int MESSAGE_WRITE = 1;
    public static final int MESSAGE_TOAST = 2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.d(TAG,"Bluetooth onCreate");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bluetooth);
        sharedPreferenceController = new SharedPreferenceController(BluetoothActivity.this);
        sharedPreferenceController.clear_MacAddress();
        set_UI();

    }

    @Override
    protected void onResume() {
        super.onResume();
        //set_UI();//disconnection button works only when
        //load_Data();
        //listen_ForData();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        //load_Data();
        //set_UI();

    }

    public void set_UI(){
        toolbarBluetooth = findViewById(R.id.toolbar_Bluetooth);
        setSupportActionBar(toolbarBluetooth);
        textViewMoisture1 = findViewById(R.id.textView_Moisture1);
        textViewMoisture2 = findViewById(R.id.textView_Moisture2);
        textViewTemperature1 = findViewById(R.id.textView_Temperature1);
        textViewTemperature2 = findViewById(R.id.textView_Temperature2);

        buttonPair = findViewById(R.id.button_Pair);
        buttonPair.setOnClickListener(buttonPairOnclick);

        buttonDisconnect = findViewById(R.id.button_Disconnect);//disconnect button
        buttonDisconnect.setOnClickListener(buttonDisconnectOnclick);//disconnect button

        buttonTime1 = findViewById(R.id.button_Time1);//refreshing button
        buttonTime1.setOnClickListener(buttonTime1Onclick);//refreshing button

        buttonStop = findViewById(R.id.button_StopRead);
        buttonStop.setOnClickListener(buttonStopOnclick);

        // not using these buttons
        buttonTime2 = findViewById(R.id.button_Time2);
        buttonTime2.setOnClickListener(buttonTime2Onclick);
        buttonTime3 = findViewById(R.id.button_Time3);
        buttonTime3.setOnClickListener(buttonTime3Onclick);
        buttonTime4 = findViewById(R.id.button_Time4);
        buttonTime4.setOnClickListener(buttonTime4Onclick);


        buttonListenTest = findViewById(R.id.button_Listen);//refreshing data does not work!!!
        buttonListenTest.setOnClickListener(buttonTime1Onclick);

    }


    private Button.OnClickListener buttonPairOnclick = new Button.OnClickListener(){
        @Override
        public void onClick(View v) {
            search_Device();//find the availabe device list by click pairButton
            BluetoothPairFragment bluetoothPairFragment = new BluetoothPairFragment();
            bluetoothPairFragment.show(getSupportFragmentManager(), "go to BluetoothPairFragment page");

        }
    };



    private Button.OnClickListener buttonDisconnectOnclick = new Button.OnClickListener(){
        @Override
        public void onClick(View v) {//disconnect blt socket
            bluetooth_Disconnect();//disconnect bluetooth
        }
    };

    private Button.OnClickListener buttonStopOnclick = new Button.OnClickListener(){
        @Override
        public void onClick(View v) {//stop receiving data
            sendSignal("0");//don't use this stop function
            try {
                TimeUnit.SECONDS.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            msg("Data stopped!");
            //TODO add thread stop function
        }
    };

    private Button.OnClickListener buttonTime1Onclick = new Button.OnClickListener(){//refreshing
        @Override
        public void onClick(View v) {
            sendSignal("100");
            try {
                TimeUnit.SECONDS.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            //listen_ForData();
        }
    };

    //all the following buttons do not work when returning to this activity
    //not using.....

    private Button.OnClickListener buttonListenOnclick= new Button.OnClickListener(){//not use any more
        @Override
        public void onClick(View v) {
            bluetooth_Disconnect();//disconnect bluetooth
            try {
                TimeUnit.SECONDS.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            pair_Device();
            try {
                TimeUnit.SECONDS.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            listen_ForData();
        }
    };

    private Button.OnClickListener buttonTime2Onclick = new Button.OnClickListener(){

        @Override
        public void onClick(View v) {
            //sendSignal("2");
            //listen_ForData();
        }
    };
    private Button.OnClickListener buttonTime3Onclick = new Button.OnClickListener(){
        @Override
        public void onClick(View v) {
            //sendSignal("3");
            //listen_ForData();
        }
    };
    private Button.OnClickListener buttonTime4Onclick = new Button.OnClickListener(){
        @Override
        public void onClick(View v) {
            //sendSignal("4");
            //listen_ForData();
        }
    };
    // not using .......


    private void sendSignal ( String number ) {
        if ( bluetoothSocket != null ) {
            try {
                bluetoothSocket.getOutputStream().write(number.toString().getBytes());
                //msg("Time Interval: " + number + "s");
            } catch (IOException e) {
                msg("Error set time interval");
            }
        }
    }

    //TODO optimize all the bluetooth connection functions to one individual control class
    public void pair_Device(){
        String macAddress = null;
        macAddress = sharedPreferenceController.get_MacAddress();
        bluetooth_Connect(macAddress);
    }

    public void search_Device(){
        deviceList = find_Pair_Bluetooth();//get bluetooth devices
    }

    public ArrayList<String> find_Pair_Bluetooth(){//return available bluetooth devices list
        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();//search bluetooth signal and get adapter
        if(bluetoothAdapter==null){
            msg("Bluetooth Device is not available!");
        }else if (!bluetoothAdapter.isEnabled()){//turn on the bluetooth
            Intent turnOnBluetooth = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(turnOnBluetooth,1);
        }

        pairedDevices = bluetoothAdapter.getBondedDevices();
        ArrayList<String> list = new ArrayList<>();
        if (pairedDevices.size()>0){
            for (BluetoothDevice BT : pairedDevices){
                list.add(BT.getName().toString() + "\n" + BT.getAddress().toString());//add the devices to list array
            }
        }else{
            msg("Bluetooth Devices are not found!");
        }
        return list;
    }

    public void bluetooth_Connect(String address){//BT connect
        boolean connectSuccess = true;
        if (address == null){
            msg("Please select devices first!");
        }
        else{
            try{
                if(bluetoothSocket==null ||!isBTConnected){
                    //BluetoothAdapter myBluetooth = BluetoothAdapter.getDefaultAdapter();//for testing how to avoid connect automatically
                    BluetoothDevice remoteDevice = bluetoothAdapter.getRemoteDevice(address);
                    bluetoothSocket = remoteDevice.createInsecureRfcommSocketToServiceRecord(myUUID);
                    bluetoothAdapter.cancelDiscovery();
                    bluetoothSocket.connect();
                }
            }catch(IOException e){
                connectSuccess = false;
            }
        }

        if(!connectSuccess){
                msg("Bluetoth Connection Failed!");
        }else{
              msg("Bluetooth Connected");
              isBTConnected = true;
        }
    }

    public void bluetooth_Disconnect(){
        if(bluetoothSocket!=null){
            try {
                bluetoothSocket.close();
                bluetoothSocket = null;//set socket to be null for reconnect
                msg("Bluetooth Disconnected!");
            }catch (IOException e){
                msg("error occured from disconnection!");
            }
        }else{
            msg("Already Disconnected!");
        }
    }

    public void listen_ForData()
    {
        try {
            if (bluetoothSocket!=null){
                inputStream=bluetoothSocket.getInputStream();
            }
            else{
                inputStream = new InputStream() {
                    @Override
                    public int read() throws IOException {
                        return 0;
                    }
                };
            }
        } catch (IOException e) {
            e.printStackTrace();
            Log.d(TAG, "inputStream error: " + e);
        }

        final Handler handler = new Handler();
        stopThread = false;
        //buffer = new byte[1024];
        Thread thread  = new Thread(new Runnable()
        {
            @RequiresApi(api = Build.VERSION_CODES.KITKAT)
            public void run()
            {
                while(!Thread.currentThread().isInterrupted() && !stopThread)
                {
                    try
                    {
                        int byteCount = inputStream.available();
                        if(byteCount > 0)
                        {
                            byte[] rawBytes = new byte[1024];
                            int numBytes = inputStream.read(rawBytes);//read the byte from input stream
                            //String string=new String(rawBytes,"US-ASCII");//same as the line below
                            //String string=new String(rawBytes,"UTF-8");//seems to be redundant
                            final String stringData = new String(rawBytes, 0, numBytes,"UTF-8");
                            Log.d(TAG, "pass string: "+ stringData);

                            //readMessage.sendToTarget();//to be used in future
                            //Handler newhandler =readMessage.getTarget();
                            /******* not use these code right now, could be used later on
                            Message readMessage = handler.obtainMessage(MESSAGE_READ, numBytes, -1, rawBytes);//to be used in future
                            final byte[] readbuff = (byte[])readMessage.obj;
                            final String tempMsg=new String(readbuff,0,readMessage.arg1);
                             *******/
                            handler.post(new Runnable() {
                                public void run()
                                {
                                    data = stringData;//receiving one sensor's value only
                                    load_Data();
                                    //msg("receiving: "+ moistureValue);
                                }
                            });
                            //Thread.sleep(5000);
                        }
                        Thread.sleep(5000);
                    }
                    catch (IOException | InterruptedException ex)
                    //catch (IOException e)
                    {
                        stopThread = true;
                    }
                }
            }
        });
        thread.start();
    }

    public void load_Data(){
        if(data != null){
            dataController = new DataController(data);
            moistureValue = dataController.getList_moiture();//output is ArrayList<> of string
            tempValue = dataController.getList_temp();//output is ArrayList<> of string
        }else{
            dataController = new DataController();
        }

        int min_moisture = dataController.find_Min_Moisture();
        double humidity = (750-min_moisture)/8;
        //String[] string_moisture = moistureValue.toArray(new String[moistureValue.size()]);//redundant
        textViewMoisture2.setText(String.valueOf(humidity)+ " %RH");
        //textViewMoisture2.append(moistureValue,2,11);//using this method causing crashing
        //save to moisture string to sharePreference, to be get from another activity
        sharedPreferenceController.save_MoistureData(String.valueOf(min_moisture));

        int min_temperarature = dataController.find_Min_Temperature();
        //String[] string_temp = tempValue.toArray(new String[tempValue.size()]);//redundant
        textViewTemperature2.setText(String.valueOf(min_temperarature) + " C°");
        //save to temperature string to sharePreference, to be get from another activity
        sharedPreferenceController.save_TemperatureData(String.valueOf(min_temperarature));
        //testing for sharedPreferenceController to get data
        String test = sharedPreferenceController.get_MoistureData();
        Log.d(TAG, "SharedPreference data test: " + test);
    }

    private void msg (String s) {
        Toast.makeText(getApplicationContext(), s, Toast.LENGTH_SHORT).show();
    }

    public ArrayList<String> getDeviceList(){
        return deviceList;
    }
}