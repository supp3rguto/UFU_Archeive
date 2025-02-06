package lab06.exercise02;
/*
*
* @author augusto
 */
public class Main {
    public static void main(String[] args) {
        Acao acao = new Acao("MSFT34", 100.0);
        AcaoBroker corretor = new AcaoBroker();

        Investidor investidor1 = new Investidor("Augusto Barbosa", 110.0, 230.0, corretor);
        Investidor investidor2 = new Investidor("Fabiola Souza", 125.0, 380.0, corretor);

        acao.addObserver(investidor1);
        acao.addObserver(investidor2);

        // Simulando uma variação de preço
        acao.setPreco(300.0);
        acao.setPreco(344.0);

    }
}