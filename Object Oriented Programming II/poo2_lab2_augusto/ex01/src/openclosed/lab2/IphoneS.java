package openclosed.lab2;

public class IphoneS implements Celular {
    
@Override
public String getModelo() {
        return "Iphone S";
    }

    @Override
    public void fazLigacao() {
        System.out.println("Ligacao feita pelo Iphone S");
    }

    @Override
    public void tiraFoto() {
        System.out.println("Foto tirada pelo Iphone S");
    }
}
