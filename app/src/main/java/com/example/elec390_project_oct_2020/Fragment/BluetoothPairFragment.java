package com.example.elec390_project_oct_2020.Fragment;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.fragment.app.DialogFragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.example.elec390_project_oct_2020.BluetoothActivity;
import com.example.elec390_project_oct_2020.R;
import com.example.elec390_project_oct_2020.SharedPreference.SharedPreferenceController;

import java.util.ArrayList;
import java.util.Objects;
import java.util.concurrent.TimeUnit;


public class BluetoothPairFragment extends DialogFragment {

    protected TextView textViewBluetoothFragment = null;
    protected ListView listViewBluetoothFragment = null;
    protected ArrayAdapter deviceListAdapter = null;

    private SharedPreferenceController sharedPreferenceController = null;


    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view =inflater.inflate(R.layout.fragment_bluetooth_pair,container,false);
        sharedPreferenceController = new SharedPreferenceController(Objects.requireNonNull(getActivity()));
        set_UI(view);
        return view;
    }

    public void set_UI(View view){
        getDialog().getWindow().setLayout(1500,1500);
        textViewBluetoothFragment = view.findViewById(R.id.textView_BluetoothFragement);
        listViewBluetoothFragment = view.findViewById(R.id.listView_bluetoothFragment);
        ArrayList<String> list = ((BluetoothActivity)getActivity()).getDeviceList();
        //potential error for this Context getActivity()
        deviceListAdapter = new ArrayAdapter<String>(getActivity(),android.R.layout.simple_list_item_1,list);
        listViewBluetoothFragment.setAdapter(deviceListAdapter);
        listViewBluetoothFragment.setOnItemClickListener(deviceListClickListener);
    }

    private AdapterView.OnItemClickListener deviceListClickListener = new AdapterView.OnItemClickListener() {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            String info = ((TextView)view).getText().toString();
            String address = info.substring(info.length()-17);
            sharedPreferenceController.save_MacAddress(address);//save to sharedPreference
            ((BluetoothActivity)getActivity()).pair_Device();//connect to the devic
            /******
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            ******/
            ((BluetoothActivity)getActivity()).listen_ForData();//list for data right after connection
            getDialog().dismiss();
        }
    };


}