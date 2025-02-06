package lab07.exercise01;
/*
 *
 * @author augusto
 */
public class Capuccino extends BebidaTemplate{

    @Override
    void prepararBebida() {
        System.out.println("Preparando o Capuccino...");
    }

    @Override
    void adicionaCondimento() {
        System.out.println("Acrescentando leite no cafe");
    }
}