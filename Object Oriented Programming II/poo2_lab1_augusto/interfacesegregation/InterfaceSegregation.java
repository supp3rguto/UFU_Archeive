package interfacesegregation;

public class InterfaceSegregation {

    public InterfaceSegregation() {
        doCorrectImplementation();
    }


    public void doCorrectImplementation() {
        /**
         * Adicione aqui seu código refatorado com referências a métodos e classes contidas no pacote interfacesegregation.correct
         */
        interfacesegregation.correct.Crow crow = new interfacesegregation.correct.Crow();
        interfacesegregation.correct.Penguin penguin = new interfacesegregation.correct.Penguin();

        crow.eat();
        crow.sleep();
        crow.fly();

        penguin.eat();
        penguin.sleep();
    }

    public static void main(String [] args) {
        InterfaceSegregation is = new InterfaceSegregation();
    }

}
