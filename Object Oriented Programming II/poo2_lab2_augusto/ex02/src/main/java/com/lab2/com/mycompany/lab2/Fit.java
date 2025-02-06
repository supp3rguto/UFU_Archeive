package com.mycompany.lab2;

public class Fit implements IVehicle{
    @Override
    public void start() {
        System.out.println("Ligando Fit");
    }

    @Override
    public void drive() {
        System.out.println("Rodando Fit");
    }

    @Override
    public void stop() {
        System.out.println("Parando Fit");
    }
}
