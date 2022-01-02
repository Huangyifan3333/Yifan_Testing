package com.example.elec390_project_oct_2020.Model;

public class Plant {
    private String plantName;
    private String plantDescription;
    private int moistureLevel;
    private long profileID;
    private long plantID;
    private byte[] plantImg;

    private Integer defaultImg;

    public Plant(String plantName, String plantDescription, int moistureLevel, long profileID , long plantID, byte[] plantImg) {
        this.plantName = plantName;
        this.plantDescription = plantDescription;
        this.moistureLevel = moistureLevel;
        this.profileID = profileID;
        this.plantID = plantID;
        this.plantImg = plantImg;
    }

    public Plant(String plantName, String plantDescription, int moistureLevel, long plantID, byte[] plantImg) {
        this.plantName = plantName;
        this.plantDescription = plantDescription;
        this.moistureLevel = moistureLevel;
        this.plantID = plantID;
        this.plantImg = plantImg;
    }

    public Plant(String plantName, String plantDescription, int moistureLevel, long plantID, Integer defaultImg) {
        this.plantName = plantName;
        this.plantDescription = plantDescription;
        this.moistureLevel = moistureLevel;
        this.plantID = plantID;
        this.defaultImg = defaultImg;
    }


    public Plant(String plantName, String plantDescription, int moistureLevel, byte[] plantImg) {
        this.plantName = plantName;
        this.plantDescription = plantDescription;
        this.moistureLevel = moistureLevel;
        this.plantImg = plantImg;
    }

    public Plant(String plantName, String plantDescription, int moistureLevel) {
        this.plantName = plantName;
        this.plantDescription = plantDescription;
        this.moistureLevel = moistureLevel;
    }


    public byte[] getPlantImg() {

        return plantImg;
    }

    public void setPlantImg(byte[] plantImg) {
        this.plantImg = plantImg;
    }

    public long getPlantID() {
        return plantID;
    }

    public void setPlantID(long plantID) {
        this.plantID = plantID;
    }

    public String getPlantName() {
        return plantName;
    }

    public void setPlantName(String plantName) {
        this.plantName = plantName;
    }

    public String getPlantDescription() {
        return plantDescription;
    }

    public void setPlantDescription(String plantDescription) {
        this.plantDescription = plantDescription;
    }

    public int getMoistureLevel() {
        return moistureLevel;
    }

    public void setMoistureLevel(int moistureLevel) {
        this.moistureLevel = moistureLevel;
    }

    public long getProfileID() {
        return profileID;
    }

    public void setProfileID(long profileID) {
        this.profileID = profileID;
    }
}
