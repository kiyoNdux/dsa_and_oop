/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.petadoption;

/**
 *
 * @author PC
 */


public abstract class Pet {
    private String name;
    private String type;
    private int age;
    private String status;
    private boolean adopted;  

    public Pet(String name, String type, int age) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.status = "Available";
        this.adopted = false;  
    }

    public String getName() { return name; }
    public String getType() { return type; }
    public int getAge() { return age; }
    public String getStatus() { return status; }
    public boolean isAdopted() { return adopted; }

    public void setName(String name) { this.name = name; }
    public void setType(String type) { this.type = type; }
    public void setAge(int age) { this.age = age; }
    public void setStatus(String status) { this.status = status; }
    public void setAdopted(boolean adopted) { this.adopted = adopted; }

    // Abstract method (forces subclasses to define their own behavior)
    public abstract String makeSound();
    public abstract String eat();

    @Override
    public String toString() {
        return name + " (" + type + ", " + age + " yrs)";
    }
}

