package com.example.elec390_project_oct_2020;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
//TODO: ADD A EDIT TEXT TO ADD PROFILE

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    protected Button startGardenButton;
    protected TextView appNameTextView;
    protected Button blueToothButton = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d(TAG,"Main Activity: onCreate Called");
        setupUI();
    }

    void setupUI() {
        startGardenButton = (Button) findViewById(R.id.startGardenButton);
        appNameTextView = (TextView) findViewById(R.id.appNameTextView);
        startGardenButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
            goToProfileActivity();
            }
        });
        blueToothButton = (Button)findViewById(R.id.buttonBluetooth);
        blueToothButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goToBluetoothActivity();
            }
        });
    }

    void goToProfileActivity(){
        Intent intent = new Intent(this,profileActivity.class);
        startActivity(intent);
    }

    void goToBluetoothActivity(){
        Intent intent = new Intent(this, BluetoothActivity.class);
        startActivity(intent);
    }


}