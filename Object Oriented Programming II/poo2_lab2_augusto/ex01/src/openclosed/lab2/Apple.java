package openclosed.lab2;

public class Apple implements FabricanteCelular{

    @Override
    public Celular constroiCelular(String modelo) {
        if(modelo.equals("IphoneX")){
            return new IphoneX();
        }else if (modelo.equals("IphoneS")){
            return new IphoneS();
        }
        else{
            return null;
        }
    }

}