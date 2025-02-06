package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Espresso implements Cafe{

    @Override
    public double custo() {
        return 12.00;
    }

    @Override
    public String getDescricao() {
        return "Cafe Espresso";
    }
}