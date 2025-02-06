package lab04.exercise01;
/**
 *
 * @author augusto
 */
public class Tomate extends Decorator {

    public Tomate(Pizza pizza) {
        super(pizza);
    }

    @Override
    public double custo() {
        return pizza.custo() + 2.0;
    }

    @Override
    public String getDescricao() {
        return pizza.getDescricao() + " com tomate";
    }

}