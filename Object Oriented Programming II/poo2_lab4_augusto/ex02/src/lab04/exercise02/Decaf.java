package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Decaf implements Cafe{

    @Override
    public double custo() {
        return 8.00;
    }

    @Override
    public String getDescricao() {
        return "Cafe Descafeinado";
    }
}