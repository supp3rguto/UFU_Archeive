package openclosed.lab2;

public class Galaxy8 implements Celular {
    
    @Override
    public String getModelo() {
        return "Galaxy 8";
    }

    @Override
    public void fazLigacao() {
        System.out.println("Ligacao feita pelo Galaxy 8");
    }

    @Override
    public void tiraFoto() {
        System.out.println("Foto tirada pelo Galaxy 8");
    }
}
