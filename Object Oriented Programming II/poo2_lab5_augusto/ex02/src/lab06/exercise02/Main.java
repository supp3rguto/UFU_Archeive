package lab06.exercise02;

public class Main {
    public static void main(String[] args) {
        CarroFachada carroFachada = new CarroFachada();
        System.out.println("Info Partida***");
        carroFachada.iniciaCorrida();
        System.out.println("Info Chegada***");
        carroFachada.finalizaCorrida();
    }
}