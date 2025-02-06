package com.mycompany.lab2;

public class Civic implements IVehicle{
    @Override
    public void start() {
        System.out.println("Ligando Civic");
    }

    @Override
    public void drive() {
        System.out.println("Dirigindo Civic");
    }

    @Override
    public void stop() {
        System.out.println("Parando Civic");
    }
}
