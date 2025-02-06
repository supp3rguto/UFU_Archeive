package lab07.exercise01;
/*
 *
 * @author augusto
 */
public class Cafe extends BebidaTemplate{

    @Override
    void prepararBebida() {
        System.out.println("Preparando o Café...");
    }

    @Override
    void adicionaCondimento() {
        System.out.println("Duas colheres de açucar no café");
        System.out.println("Acrescentando canela no café");
    }
}