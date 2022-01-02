package com.example.elec390_project_oct_2020.Fragment;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.DialogFragment;

import com.example.elec390_project_oct_2020.DataBase.DataBaseHelper;
import com.example.elec390_project_oct_2020.Model.Plant;
import com.example.elec390_project_oct_2020.R;
import com.example.elec390_project_oct_2020.profileActivity;

public class insertPlantDialogFragment extends DialogFragment {
    protected EditText plantNameEditText, plantDescriptionEditText, waterThresholdEditText;
    protected Button savePlantButton, cancelPlantButton;
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_insert_plant,container,false);
        setupUI(view);


        savePlantButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //TODO: remove profile ID from the table and change all the variables to non-constant <-- at the end
                //TODO: get image from gallery and insert here to save in DATABASE
                String plantName = plantNameEditText.getText().toString();
                String plantDescription = plantDescriptionEditText.getText().toString();
                String moistureLevel = waterThresholdEditText.getText().toString();
                int moistureLevelint = Integer.parseInt(moistureLevel);
                DataBaseHelper dataBaseHelper = new DataBaseHelper(getActivity());
                if(!(plantName.equals("") || plantDescription.equals("")||moistureLevel.equals("")) ) {
                    dataBaseHelper.insertPlant(new Plant(plantName, plantDescription, moistureLevelint));
                    ((profileActivity)getActivity()).loadListView();
                    getDialog().dismiss();
                }else{
                    Toast toast = new Toast(getActivity());
                    toast.makeText(getActivity(),"Invalid input",Toast.LENGTH_SHORT).show();
                }
            }
        });

        cancelPlantButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getDialog().dismiss();
            }
        });
        return view;
    }

    protected void setupUI(View view){
        plantNameEditText = (EditText) view.findViewById(R.id.plantNameEditText);
        plantDescriptionEditText = (EditText) view.findViewById(R.id.plantDescriptionEditText);
        waterThresholdEditText = (EditText) view.findViewById(R.id.waterThresholdEditText);
        savePlantButton = (Button) view.findViewById(R.id.savePlantButton);
        cancelPlantButton = (Button) view.findViewById(R.id.cancelPlantButton);

    }
}
