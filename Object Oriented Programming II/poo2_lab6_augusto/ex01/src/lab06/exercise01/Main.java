package lab06.exercise01;
/*
*
* @author augusto
 */
public class Main {
    public static void main(String[] args) {

        Subject cet = new CET();
        Observer prefeitura = new Prefeitura();
        cet.addObserver(prefeitura);
        Observer aeroporto = new Aeroporto();
        cet.addObserver(aeroporto);

        cet.setUmidade(30);
        cet.setUmidade(60);
    }
}