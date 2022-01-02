package com.example.elec390_project_oct_2020.DataBase;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;
import android.widget.Toast;

import com.example.elec390_project_oct_2020.Model.Plant;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;



public class DataBaseHelper  extends SQLiteOpenHelper {
    private static final String TAG = "DatabaseHelper";
    private Context context;

    /***************************CREATING TABLE*******************************/
    String CREATE_TABLE_PLANT = "CREATE TABLE " + plantConfig.PLANT_TABLE_NAME +
            " (" + plantConfig.COLUMN_PLANT_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
            plantConfig.COLUMN_PLANT_NAME + " TEXT NOT NULL," + plantConfig.COLUMN_PLANT_DESCRIPTION + " TEXT NOT NULL," +
            plantConfig.COLUMN_PLANT_MOISTURE + " INTEGER," + plantConfig.COLUMN_PLANT_IMAGE + " BLOB)";




    public DataBaseHelper(Context context) {
        super(context, plantConfig.DATABASE_NAME, null, plantConfig.DATABASE_VERSION);
        this.context = context;
    }


    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {

        sqLiteDatabase.execSQL(CREATE_TABLE_PLANT);
        Log.d(TAG, CREATE_TABLE_PLANT);
        Log.d(TAG, "Database Created");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
    } // Only used when you upgrade you application

    //Plant functions
    public long insertPlant(Plant plant){
        long id = -1;
        SQLiteDatabase db = getWritableDatabase();
        ContentValues contentValues = new ContentValues();

        contentValues.put(plantConfig.COLUMN_PLANT_NAME,plant.getPlantName());
        contentValues.put(plantConfig.COLUMN_PLANT_DESCRIPTION,plant.getPlantDescription());
        contentValues.put(plantConfig.COLUMN_PLANT_MOISTURE,plant.getMoistureLevel());
        //TODO: add to gallery from add plants
        try {
            id = db.insertOrThrow(plantConfig.PLANT_TABLE_NAME, null, contentValues);
        } catch (SQLException e) {
            Log.d(TAG, "Exception: " + e);
            Toast.makeText(context, "Insert Assignment Operation Failed!" + e, Toast.LENGTH_LONG).show();
        } finally {
            db.close();
        }
        return id;
    }

    public List<Plant> getAllPlants() {
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = null;
        try {
            cursor = db.query(plantConfig.PLANT_TABLE_NAME, null, null, null, null, null, null);
            if (cursor != null) {
                if (cursor.moveToFirst()) {
                    List<Plant> plants = new ArrayList<>();
                    do {
                        long plantID = cursor.getLong(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_ID));
                        String plantName = cursor.getString(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_NAME));
                        String plantDescription = cursor.getString(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_DESCRIPTION));
                        int plantMoistureLevel = cursor.getInt(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_MOISTURE));
                        byte[] img = cursor.getBlob(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_IMAGE));
                        plants.add(new Plant(plantName,plantDescription,plantMoistureLevel,plantID,img));
                    } while (cursor.moveToNext());
                    return plants;
                }
            }
        } catch (SQLException e) {
            Log.d(TAG, "Exception: " + e);
            Toast.makeText(context, "Operation Failed!" + e, Toast.LENGTH_LONG).show();
        } finally {
            if (cursor != null) {
                cursor.close();
            }
            db.close();
        }
        return Collections.emptyList();
    }
    public void deletePlant(long plantID) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(plantConfig.PLANT_TABLE_NAME, plantConfig.COLUMN_PLANT_ID + " = ?", new String[]{String.valueOf(plantID)});
    }
    public Integer updateImageByPlantID(long PlantID, byte[] PlantImage){ //read course by code (handy for main activity
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        //set method
        contentValues.put(plantConfig.COLUMN_PLANT_IMAGE, PlantImage);
        try{//if problem encountered
            //delete entire row
            if(db!=null&&db.isOpen()){
                db.update(plantConfig.PLANT_TABLE_NAME,contentValues, plantConfig.COLUMN_PLANT_ID + "= ?",new String[]{String.valueOf(PlantID)});
            }//end if null cursor
        }//end try
        catch(SQLException e){//assign exception as e
            //catch like in insertCourse
            Log.d(TAG, "SQLite Exeption catch: "+e);
            Toast.makeText(context,"SQLite exception catch"+e, Toast.LENGTH_LONG);

        }//end of catch
        finally{//if all else does not fail
            if(db!=null&&db.isOpen()){//if cursor is also not pointing at "nowhere" in the table
                db.close(); //close db
            }
        }//end finally
        return null;// reach end of function
    }//end of getCourseByID

    public Plant getPlantByID(long PlantID){ //read course by code (handy for main activity
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = null;//initialize cursor

        try{//if problem encountered
            //start cursor then call query
            //gets a course
            //want column equal to whatever argument will be passed for selection argument(after the =?)
            //create new string array
            //"give all courses where column course code is the value that is passed at "new String[]", or (courseCode)
            cursor = db.query(plantConfig.PLANT_TABLE_NAME,null, plantConfig.COLUMN_PLANT_ID + "= ?",new String[]{String.valueOf(PlantID)},null,null,null);
            //this will read courses from the database that meet above condition
            if(cursor!=null){
                if(cursor.moveToFirst()) {//if cursor at beginning
                    long plantID = cursor.getLong(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_ID));
                    String plantName = cursor.getString(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_NAME));
                    String plantDescription = cursor.getString(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_DESCRIPTION));
                    int plantMoistureLevel = cursor.getInt(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_MOISTURE));
                    byte[] img = cursor.getBlob(cursor.getColumnIndex(plantConfig.COLUMN_PLANT_IMAGE));


                    return new Plant(plantName,plantDescription,plantMoistureLevel,plantID,img);
                    //return new Plant(plantID,img); //return a new instance of course from configured db variables above
                }//end if move to first
            }//end if null cursor


        }//end try
        catch(SQLException e){//assign exception as e
            //catch like in insertCourse
            Log.d(TAG, "SQLite Exeption catch: "+e);
            Toast.makeText(context,"SQLite exception catch"+e, Toast.LENGTH_LONG);

        }//end of catch
        finally{//if all else does not fail
            if(cursor!=null){//if cursor is also not pointing at "nowhere" in the table
                cursor.close();//close cursor
                db.close(); //close db
            }

        }//end finally
        return null;// give null for example if no such course exists
    }
}
