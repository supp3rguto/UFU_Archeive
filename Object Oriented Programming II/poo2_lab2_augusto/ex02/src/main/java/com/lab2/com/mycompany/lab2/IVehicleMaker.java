package com.mycompany.lab2;

public interface IVehicleMaker {
    //Factory: pois é uma maneira de criar objetos de maneira flexivel e de facil manutenção.
    public IVehicle makeVehicle(String modelo);
}
