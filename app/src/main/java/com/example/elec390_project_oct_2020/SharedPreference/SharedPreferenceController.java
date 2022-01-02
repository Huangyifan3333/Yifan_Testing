package com.example.elec390_project_oct_2020.SharedPreference;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;

import com.example.elec390_project_oct_2020.R;

import java.util.ArrayList;


public class SharedPreferenceController {//this class is to control the sharedPreference
    private static final String TAG = "SharedPreferenceController";
    private SharedPreferences sharedPreferences;//define the object
    public SharedPreferenceController(Context context){//constructor
        sharedPreferences//instantiate the sharedPreference through constructor
                = context.getSharedPreferences(String.valueOf((R.string.Profile_Preference)), Context.MODE_PRIVATE);
    }

    public void save_MacAddress(String address){
        SharedPreferences.Editor editor = sharedPreferences.edit();//instantiate the sharedPreference.Editor object
        //save name into the sharedPreference
        editor.putString(String.valueOf(R.string.Bluetooth_Device_Address), address);
        editor.commit();
    }

    @SuppressLint("LongLogTag")
    public String get_MacAddress(){
        String address = null;
        try{
        address = sharedPreferences.getString(String.valueOf(R.string.Bluetooth_Device_Address),null);

        }catch (RuntimeException e){
            Log.d(TAG, "get Macaddress error: " + e);
        }
        return address;
    }

    public void clear_MacAddress(){
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString((String.valueOf(R.string.Bluetooth_Device_Address)), null);
        editor.commit();
    }

    public void save_MoistureData(String data){
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString((String.valueOf(R.string.Moisture_Data_String)),data);
        editor.commit();
    }

    public void save_MoistureData(String[] data){
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString((String.valueOf(R.string.Moisture_Data_String)),data.toString());
        editor.commit();
    }

    public void save_MoistureData(ArrayList<String> data){//override
        SharedPreferences.Editor editor = sharedPreferences.edit();
        String[] string = data.toArray(new String[data.size()]);
        editor.putString(String.valueOf(R.string.Moisture_Data_String), string.toString());
        editor.commit();
    }


    @SuppressLint("LongLogTag")
    public String get_MoistureData(){
        String data = null;
        try {
            data = sharedPreferences.getString(String.valueOf(R.string.Moisture_Data_String), null);
        }catch(RuntimeException e){
            Log.d(TAG, "get moisture error: "+ e);
        }
        return data;
    }

    public void save_TemperatureData(String data){
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString((String.valueOf(R.string.Temperature_Data_String)),data);
        editor.apply();
    }

    public void save_TemperatureData(String[] data){
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString((String.valueOf(R.string.Temperature_Data_String)),data.toString());
        editor.apply();
    }

    public void save_TemperatureData(ArrayList<String> data){//override
        SharedPreferences.Editor editor = sharedPreferences.edit();
        String[] string = data.toArray(new String[data.size()]);
        editor.putString(String.valueOf(R.string.Temperature_Data_String), string.toString());
        editor.commit();
    }


    @SuppressLint("LongLogTag")
    public String get_TemperatureData(){
        String data = null;
        try {
            data = sharedPreferences.getString(String.valueOf(R.string.Temperature_Data_String), null);
        }catch (RuntimeException e){
            Log.d(TAG, "get_TemperatureData error: "+ e);
        }
        return data;
    }
}
