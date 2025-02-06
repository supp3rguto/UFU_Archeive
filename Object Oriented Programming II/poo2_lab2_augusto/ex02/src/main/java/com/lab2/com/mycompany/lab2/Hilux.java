package com.mycompany.lab2;

public class Hilux implements IVehicle{
    @Override
    public void start() {
        System.out.println("Ligando Hilux");
    }

    @Override
    public void drive() {
        System.out.println("Rodando Hilux");
    }

    @Override
    public void stop() {
        System.out.println("Parando Hilux");
    }
}
