package com.example.elec390_project_oct_2020.DataController;

import androidx.core.content.res.TypedArrayUtils;

import java.util.ArrayList;
import java.util.List;

public class DataController {
    private String Data=null;
    private int[] list_int = null;
    private String[] list_string = null;
    private ArrayList<String> list_moisture =null;
    private ArrayList<String> list_temp =null;
    private char flag_moisture;
    private char flag_temp;

    public DataController(){//empty constructor

    }

    //Override
    public DataController(String D){
        Data = D;
        list_string = new String[Data.length()];
        list_int = new int[Data.length()];
        list_moisture = new ArrayList<>();
        list_temp = new ArrayList<>();
        flag_moisture = '\t';
        flag_temp = '\n';
    }

    public ArrayList<String> getList_moiture(){
        String[] list = null;
        list = string_To_ArrayString();
        if(list!=null){
            for (int i=0; i<list.length; ++i){
                if(i%2==0){
                list_moisture.add(list[i]);
                }
            }
        }
     return list_moisture;
    }

    public ArrayList<String> getList_temp(){
        String[] list = null;
        list = string_To_ArrayString();
        if(list!=null){
            for (int i=0; i<list.length; ++i){
                if(i%2==1){
                    list_temp.add(list[i]);
                }
            }
        }
        return list_temp;
    }

    public String[] string_To_ArrayString(){//extract each moisture vale from string to form the String array
        //odd position to store moisture value , even position to store temperature value
        //if value is not available, set '0'
        char flag = '\t';//data flag for moisture according to arduino code
        int begin_moisture =-1;
        int end_moisture = -1;
        int begin_temp =-1;
        int end_temp = -1;
        int moistureValue = 0;
        int tempValue=0;
        //int loop = 0;
        String moistureString = null;
        String tempString = null;
        begin_moisture = Data.indexOf(flag_moisture);//assign the first begin moisture poistion of char '\t'
        begin_temp = Data.indexOf(flag_temp);//assign the first begin temperature poistion of char '\n'
        for (int i=0; i<list_string.length; ++i){
            if(i%2==0) {//even number for moisture check
                if(begin_moisture!=-1) {
                    end_moisture = Data.indexOf(flag_temp, begin_moisture);//find the flag of '\n' from '\t' position
                    if (end_moisture >= begin_moisture + 3) {
                        moistureString = Data.substring(begin_moisture + 1, end_moisture);
                        //moistureValue = Integer.parseInt(moistureString);

                        begin_moisture = Data.indexOf(flag_moisture, begin_moisture);//find the new moisture value begin position
                    } else {//in case temp flag '\n' is not available
                        end_moisture = Data.indexOf(flag_moisture, begin_moisture);
                        if (end_moisture > begin_moisture + 3) {
                            moistureString = Data.substring(begin_moisture + 1, end_moisture);
                            //moistureValue = Integer.parseInt(moistureString);

                            begin_moisture = end_moisture;
                        }
                    }
                    /****
                    if (moistureString != null) {
                        moistureValue = Integer.parseInt(moistureString);
                    }
                     *****/
                    list_string[i] = moistureString;//add to even position of list
                }
            }else{//odd number for temperature value check
                if(begin_temp!=-1){
                    end_temp = Data.indexOf(flag_moisture, begin_temp);
                    if(end_temp >= begin_temp + 2){
                        tempString = Data.substring(begin_temp+1,end_temp);
                        //tempValue = Integer.parseInt(tempString);
                        begin_temp =Data.indexOf(flag_temp,begin_temp);
                    }else {//if '\t' moisture flag is not availabe
                        end_temp = Data.indexOf(flag_temp,begin_temp);
                        if(end_temp >= begin_temp + 2){
                            tempString = Data.substring(begin_temp+1, end_temp);
                            begin_temp = end_temp;
                        }
                    }
                    /*****
                    if(tempString != null){
                        tempValue = Integer.parseInt(tempString);
                    }
                     ******/
                    list_string[i] = tempString;
                }
            }
            if (end_temp >= Data.length() - 2 || end_moisture >= Data.length() -2) {//reaching the end of string
                break;
            }

        }
        return list_string;

    }


    public int[] string_To_ArrayInt(){//extract each moisture vale from string to form the Int array
        //odd position to store moisture value , even position to store temperature value
        //if value is not available, set '0'
        char flag = '\t';//data flag for moisture according to arduino code
        int begin_moisture =0;
        int end_moisture = 0;
        int begin_temp =0;
        int end_temp = 0;
        int moistureValue = 0;
        int tempValue=0;
        //int loop = 0;
        String moistureString = null;
        String tempString = null;
        begin_moisture = Data.indexOf(flag_moisture);//assign the first begin moisture poistion of char '\t'
        begin_temp = Data.indexOf(flag_temp);//assign the first begin temperature poistion of char '\n'
        for (int i=0; i<list_int.length; ++i){
            if(i%2==0) {//even number for moisture check
                if(begin_moisture!=0) {
                    end_moisture = Data.indexOf(flag_temp, begin_moisture);//find the flag of '\n' from '\t' position
                    if (end_moisture >= begin_moisture + 3) {
                        moistureString = Data.substring(begin_moisture + 1, end_moisture - 1);
                        //moistureValue = Integer.parseInt(moistureString);

                        begin_moisture = Data.indexOf(flag_moisture, begin_moisture);//find the new moisture value begin position
                    } else {//in case temp flag '\n' is not available
                        end_moisture = Data.indexOf(flag_moisture, begin_moisture);
                        if (end_moisture > begin_moisture + 3) {
                            moistureString = Data.substring(begin_moisture + 1, end_moisture - 1);
                            //moistureValue = Integer.parseInt(moistureString);

                            begin_moisture = end_moisture;
                        }
                    }
                    if (moistureString != null) {
                        moistureValue = Integer.parseInt(moistureString);
                    }
                    list_int[i] = moistureValue;//add to even position of list
                }

            }else{//odd number for temperature value check
                if(begin_temp!=0){
                    end_temp = Data.indexOf(flag_moisture, begin_temp);
                    if(end_temp >= begin_temp + 2){
                        tempString = Data.substring(begin_temp+1,end_temp-1);
                        //tempValue = Integer.parseInt(tempString);
                        begin_temp =Data.indexOf(flag_temp,begin_temp);
                    }else {//if '\t' moisture flag is not availabe
                        end_temp = Data.indexOf(flag_temp,begin_temp);
                        if(end_temp >= begin_temp + 2){
                            tempString = Data.substring(begin_temp+1, end_temp-1);
                            begin_temp = end_temp;
                        }
                    }
                    if(tempString != null){
                        tempValue = Integer.parseInt(tempString);
                    }
                    list_int[i] = tempValue;
                }
            }
            if (end_temp >= Data.length() - 2 || end_moisture >= Data.length() -2) {//reaching the end of string
                break;
            }
        }
        return list_int;
    }

    public String arrayList_To_String(ArrayList<String> data){
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < data.size(); ++i) {
            sb.append(data.get(i));
        }
        String str = sb.toString();
        return str;
    }

    public int find_Min_Moisture(){//return -1 if searching fails
        int min=-1;
        if (list_moisture!=null){
            min = 1000;
            for (int i=0; i<list_moisture.size(); ++i){
                int cur = Integer.parseInt(list_moisture.get(i));
                if (cur < min){
                    min = cur;
                }
            }
        }
        return min;
    }
    public int find_Max_Moisture(){//return -1 if searching fails
        int max=-1;
        if (list_moisture!=null){
            max = 0;
            for (int i=0; i<list_moisture.size(); ++i){
                int cur = Integer.parseInt(list_moisture.get(i));
                if (cur > max){
                    max = cur;
                }
            }
        }
        return max;
    }

    public int find_Min_Temperature(){//return -1 if searching fails
        int min=-1;
        if (list_temp!=null){
            min = 1000;
            for (int i=0; i<list_temp.size(); ++i){
                int cur = Integer.parseInt(list_temp.get(i));
                if (cur < min){
                    min = cur;
                }
            }
        }
        return min;
    }
    public int find_Max_Temperature(){//return -1 if searching fails
        int max=-1;
        if (list_temp!=null){
            max = 0;
            for (int i=0; i<list_temp.size(); ++i){
                int cur = Integer.parseInt(list_temp.get(i));
                if (cur > max){
                    max = cur;
                }
            }
        }
        return max;
    }



}
