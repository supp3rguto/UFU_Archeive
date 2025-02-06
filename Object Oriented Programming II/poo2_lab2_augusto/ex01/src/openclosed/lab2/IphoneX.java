package openclosed.lab2;

public class IphoneX implements Celular {
    
    @Override
    public String getModelo() {
        return "Iphone X";
    }

    @Override
    public void fazLigacao() {
        System.out.println("Ligacao feita pelo Iphone X");
    }

    @Override
    public void tiraFoto() {
        System.out.println("Foto tirada pelo Iphone X");
    }
}

