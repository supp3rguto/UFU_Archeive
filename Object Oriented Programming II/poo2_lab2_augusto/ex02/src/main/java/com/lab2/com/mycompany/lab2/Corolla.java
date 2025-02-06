package com.mycompany.lab2;

public class Corolla implements IVehicle{
    @Override
    public void start() {
        System.out.println("Ligando Corola");
    }

    @Override
    public void drive() {
        System.out.println("Rodando Corola");
    }

    @Override
    public void stop() {
        System.out.println("Parando Corola");
    }
}
