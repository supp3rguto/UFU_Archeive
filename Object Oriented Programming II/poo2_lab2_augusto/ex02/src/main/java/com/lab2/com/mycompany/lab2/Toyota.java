package com.mycompany.lab2;
//Factory: pois é uma maneira de criar objetos de maneira flexivel e de facil manutenção.
public class Toyota implements IVehicleMaker{

    private static Toyota instance;

    public static Toyota getInstance(){
        if(instance == null){
            instance = new Toyota();
        }
        return instance;
    }


    @Override
    public IVehicle makeVehicle(String modelo) {

        if("Corolla".equalsIgnoreCase(modelo)){
            return new Corolla();
        } else if ("Hilux".equalsIgnoreCase(modelo)){
            return new Hilux();
        }
        else if ("Etios".equalsIgnoreCase(modelo)){
            return new Etios();
        }
        return null;
    }
}