package com.mycompany.lab2;

public class City implements IVehicle{

    @Override
    public void start() {
        System.out.println("Ligando City");
    }

    @Override
    public void drive() {
        System.out.println("Dirigindo City");
    }

    @Override
    public void stop() {
        System.out.println("Parando City");
    }

}
