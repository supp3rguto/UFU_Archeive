package openclosed.lab2;

public class Samsung implements FabricanteCelular{

    @Override
    public Celular constroiCelular(String modelo) {
        if(modelo.equals("Galaxy8")){
            return new Galaxy8();
        }else if(modelo.equals("Galaxy20")){
            return new Galaxy20();
        }
        else{
            return null;
        }
    }

}
