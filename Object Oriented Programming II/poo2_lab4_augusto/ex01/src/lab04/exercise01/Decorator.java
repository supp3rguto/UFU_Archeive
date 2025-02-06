package lab04.exercise01;
/**
 *
 * @author augusto
 */
public class Decorator implements Pizza {

    protected Pizza pizza;

    public Decorator(Pizza pizza) {
        this.pizza = pizza;
    }

    @Override
    public double custo() {
        return pizza.custo();
    }

    @Override
    public String getDescricao() {
        return pizza.getDescricao();
    }

}