package lab05.exercise01;
/**
*
* @author augusto
 */
public class Main {
    public static void main(String[] args) {
        CinametecaFachada cinametecaFachada = new CinametecaFachada();

        cinametecaFachada.iniciarFilme("Avatar: Way of the Water");

        cinametecaFachada.encerrarFilme();
    }
}
