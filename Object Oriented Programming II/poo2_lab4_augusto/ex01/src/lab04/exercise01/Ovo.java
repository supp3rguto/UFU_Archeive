package lab04.exercise01;
/**
 *
 * @author augusto
 */
public class Ovo extends Decorator {

    public Ovo(Pizza pizza) {
        super(pizza);
    }

    @Override
    public double custo() {
        return pizza.custo() + 1.50;
    }

    @Override
    public String getDescricao() {
        return pizza.getDescricao() + " com ovo";
    }

}