package com.mycompany.lab2;
//Factory: pois é uma maneira de criar objetos de maneira flexivel e de facil manutenção.
public class Honda implements IVehicleMaker{

    private static Honda instance;

    public static Honda getInstance(){
        if(instance == null){
            instance = new Honda();
        }
        return instance;
    }


    @Override
    public IVehicle makeVehicle(String modelo) {

        if("City".equalsIgnoreCase(modelo)){
            return new City();
        } else if ("Civic".equalsIgnoreCase(modelo)){
            return new Civic();
        }
        else if ("Fit".equalsIgnoreCase(modelo)){
            return new Fit();
        }
        return null;
    }
}