package openclosed.lab2;

public class FabricanteCelularSingleton {

    private static Apple apple;
    private static Samsung samsung;

    public static FabricanteCelular getInstance(String fabricante) {
        if (fabricante.equalsIgnoreCase("apple")) {
            if (apple == null) {
                apple = new Apple();
            }
            return apple;
        } else if (fabricante.equalsIgnoreCase("samsung")) {
            if (samsung == null) {
                samsung = new Samsung();
            }
            return samsung;
        } else {
            return null;
        }
    }
}
