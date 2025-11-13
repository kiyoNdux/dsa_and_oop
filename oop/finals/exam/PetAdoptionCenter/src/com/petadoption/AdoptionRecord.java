/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.petadoption;

/**
 *
 * @author PC
 */

public class AdoptionRecord {
    private String adopterName;
    private String contactInfo;
    private String adoptionDate;
    private String petName;
    private String notes;

    public AdoptionRecord(String adopterName, String contactInfo, String adoptionDate, String petName, String notes) {
        this.adopterName = adopterName;
        this.contactInfo = contactInfo;
        this.adoptionDate = adoptionDate;
        this.petName = petName;
        this.notes = notes;
    }

    public String getAdopterName() { return adopterName; }
    public String getContactInfo() { return contactInfo; }
    public String getAdoptionDate() { return adoptionDate; }
    public String getPetName() { return petName; }
    public String getNotes() { return notes; }

    public void setAdopterName(String adopterName) { this.adopterName = adopterName; }
    public void setContactInfo(String contactInfo) { this.contactInfo = contactInfo; }
    public void setAdoptionDate(String adoptionDate) { this.adoptionDate = adoptionDate; }
    public void setPetName(String petName) { this.petName = petName; }
    public void setNotes(String notes) { this.notes = notes; }
}

