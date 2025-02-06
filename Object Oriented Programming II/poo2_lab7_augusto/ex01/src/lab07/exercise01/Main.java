package lab07.exercise01;
/*
 *
 * @author augusto
 */
public class Main {
    public static void main(String[] args) {

        System.out.println("\nSelecionado: Café---");

        BebidaTemplate cafe = new Cafe();
        cafe.preparaComanda();

        System.out.println("\nSelecionado: Capuccino---");

        BebidaTemplate capuccino = new Capuccino();
        capuccino.preparaComanda();


        System.out.println("\nSelecionado: Chá---");

        BebidaTemplate cha = new Cha();
        cha.preparaComanda();
    }
}