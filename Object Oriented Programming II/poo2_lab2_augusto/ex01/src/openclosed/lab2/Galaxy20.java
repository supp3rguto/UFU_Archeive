package openclosed.lab2;

public class Galaxy20 implements Celular {
    
    @Override
    public String getModelo() {
        return "Galaxy 20";
    }

    @Override
    public void fazLigacao() {
        System.out.println("Ligacao feita pelo Galaxy 20");
    }

    @Override
    public void tiraFoto() {
        System.out.println("Foto tirada pelo Galaxy 20");
    }
}
