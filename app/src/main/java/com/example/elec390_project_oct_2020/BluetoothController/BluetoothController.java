package com.example.elec390_project_oct_2020.BluetoothController;


import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import com.example.elec390_project_oct_2020.SharedPreference.SharedPreferenceController;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Set;
import java.util.UUID;

public class BluetoothController {
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
    private String moistureValue;
    private String temperatureValue;

    public static final int MESSAGE_READ = 0;
    public static final int MESSAGE_WRITE = 1;
    public static final int MESSAGE_TOAST = 2;

    //TODO migrate the bluetooth functions into this class
    //TODO reconnect paire dosn't work after disconnect
    public BluetoothController() {
    }



}
