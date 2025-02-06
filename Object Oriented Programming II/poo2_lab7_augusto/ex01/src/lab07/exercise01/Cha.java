package lab07.exercise01;
/*
 *
 * @author augusto
 */
public class Cha extends BebidaTemplate {

    @Override
    void prepararBebida() {
        System.out.println("Preparando o Chá...");
    }

    @Override
    void adicionaCondimento() {
        System.out.println("Colocando sachê de ervas no cha");
    }
}