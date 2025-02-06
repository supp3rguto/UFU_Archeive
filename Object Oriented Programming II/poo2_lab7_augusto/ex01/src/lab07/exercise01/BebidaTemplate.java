package lab07.exercise01;
/*
 *
 * @author augusto
 */
abstract class BebidaTemplate {

    public BebidaTemplate() {
    }

    public void aquecerAgua(){
        System.out.println("Começar a ferver a aguá");
    }

    abstract void prepararBebida();

    public void colocaXicara(){
        System.out.println("Enchendo a xicara");
    }

    abstract void adicionaCondimento();

    public void preparaComanda(){
        aquecerAgua();
        prepararBebida();
        colocaXicara();
        adicionaCondimento();
    }
}