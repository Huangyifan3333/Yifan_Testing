package com.example.elec390_project_oct_2020;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.example.elec390_project_oct_2020.DataBase.DataBaseHelper;
import com.example.elec390_project_oct_2020.Fragment.insertPlantDialogFragment;
import com.example.elec390_project_oct_2020.Model.Plant;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;
import java.util.List;


public class profileActivity extends AppCompatActivity {
    private static final String TAG = "profileActivity";
    ListView plantListView;
    /***************************TESTING FOR CUSTOM LISTVIEW *******************************************************************/

    protected FloatingActionButton addPlantButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);
        plantListView = (ListView) findViewById(R.id.plantListView);
        addPlantButton = (FloatingActionButton) findViewById(R.id.addPlantFloatingButton);
        loadListView();

        plantListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                /*DataBaseHelper dataBaseHelper = new DataBaseHelper(profileActivity.this);
                Intent intent = new Intent(profileActivity.this,plantActivity.class);
                List<Plant> plants = new ArrayList<Plant>();
                plants = dataBaseHelper.getAllPlants();
                intent.putExtra(getString(R.string.plant_name), plants.get(position).getPlantName());
                intent.putExtra(getString(R.string.plant_description), plants.get(position).getPlantDescription());
                //intent.putExtra(getString(R.string.plant_image), plants.get(position).getPlantImg());
                intent.putExtra(getString(R.string.plant_id),plants.get(position).getPlantID());
                intent.putExtra(getString(R.string.plant_threshold),plants.get(position).getMoistureLevel());
                if(plants.get(position).getPlantImg()!=null){
                    intent.putExtra(getString(R.string.plant_image),plants.get(position).getPlantImg());

                }
                Log.d(TAG,"SENT : Plant Name: " + plants.get(position).getPlantName());*/
                Intent intent = new Intent(profileActivity.this,plantActivity.class);
                Plant currentPlant = (Plant) adapterView.getItemAtPosition(position);//create Plant object from grid item
                intent.putExtra("PLANT_ID", String.valueOf(currentPlant.getPlantID())); //method in Plant should be exactly
                startActivity(intent);

            }
        });

        addPlantButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                insertPlantDialogFragment dialog = new insertPlantDialogFragment();
                dialog.show(getSupportFragmentManager(),"Insert Plant Fragment");
            }
        });

    }

    @Override
    protected void onResume() {
        loadListView();
        super.onResume();
    }

    public void loadListView(){
        DataBaseHelper dataBaseHelper = new DataBaseHelper(this);
        List<Plant> plants = new ArrayList<Plant>();
        plants = dataBaseHelper.getAllPlants();
        ArrayList<Plant> plantList = new ArrayList<Plant>();
        for (int i = 0; i<plants.size();i++){
            if(plants.get(i).getPlantImg()!=null) {
                plantList.add(new Plant(plants.get(i).getPlantName(),
                            plants.get(i).getPlantDescription(),
                            plants.get(i).getMoistureLevel(),
                            plants.get(i).getPlantID(),
                            plants.get(i).getPlantImg()));
            }else{
                plantList.add(new Plant(plants.get(i).getPlantName(),
                        plants.get(i).getPlantDescription(),
                        plants.get(i).getMoistureLevel(),
                        plants.get(i).getPlantID(),
                        R.drawable.plant_img));
            }
        }
        CustomListView customListView = new CustomListView(this,plantList);
        plantListView.setAdapter(customListView);
    }
}