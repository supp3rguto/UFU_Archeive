package lab3.exercise01;
/**
 *
 * @author augusto
 */
public class Main {

    public static void main(String[] args) {

        Pato patoDomestico = new PatoDomestico();
        Ave patoUniversal = new AdapterPatoAve(patoDomestico);
        patoUniversal.EmitirSom();
        patoUniversal.Voar();

        Pavao pavaoAzul = new PavaoAzul();
        Ave pavaoUniversal = new AdapterPavaoAve(pavaoAzul);
        pavaoUniversal.EmitirSom();
        pavaoUniversal.Voar();


    }
}
