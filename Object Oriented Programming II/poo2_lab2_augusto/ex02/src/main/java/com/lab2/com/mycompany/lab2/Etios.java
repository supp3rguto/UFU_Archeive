package com.mycompany.lab2;

public class Etios implements IVehicle{
    @Override
    public void start() {
        System.out.println("Ligando Etios");
    }

    @Override
    public void drive() {
        System.out.println("Rodando Etios");
    }

    @Override
    public void stop() {
        System.out.println("Parando Etios");
    }
}
