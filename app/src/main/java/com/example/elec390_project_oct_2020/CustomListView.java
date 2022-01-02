package com.example.elec390_project_oct_2020;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.elec390_project_oct_2020.Model.Plant;

import java.util.ArrayList;

public class CustomListView extends ArrayAdapter<Plant> {
    Context mcontext ;
    //TODO: Change this to an ArrayList;
    private ArrayList<Plant> plantList;
    private Activity context;
    public CustomListView(@NonNull Activity context, ArrayList<Plant> plant) {
        super(context, R.layout.listview_layout,plant);
        this.context = context;
        this.plantList = plant;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        View r = convertView;
        ViewHolder viewHolder = null;
        if(r==null){
            LayoutInflater layoutInflater = context.getLayoutInflater();
            r = layoutInflater.inflate(R.layout.listview_layout,null,true);
            viewHolder = new ViewHolder(r);
            r.setTag(viewHolder);
        }else{
            viewHolder = (ViewHolder) r.getTag();
        }
        if(plantList.get(position).getPlantImg()!=null){
            Bitmap p = BitmapFactory.decodeByteArray(plantList.get(position).getPlantImg(), 0, plantList.get(position).getPlantImg().length); //get blob from objects arraylist
            Drawable d = new BitmapDrawable(p);
            viewHolder.plantImage.setImageDrawable(d);
        }else{
            viewHolder.plantImage.setImageResource(R.drawable.plant_img);
        }
        viewHolder.plantName.setText(plantList.get(position).getPlantName());
        viewHolder.plantDescription.setText(plantList.get(position).getPlantDescription());
        return r;
    }

    class ViewHolder{
        TextView plantName;
        TextView plantDescription;
        ImageView plantImage;
        ViewHolder(View v){
            plantName = (TextView) v.findViewById(R.id.plantNameTextView);
            plantDescription = (TextView)v.findViewById(R.id.plantDescriptionTextView);
            plantImage = (ImageView) v.findViewById(R.id.plantImageView);
        }
    }

}
