package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Chocolate extends Decorator{

    public Chocolate(Cafe cafe) {
        super(cafe);
    }

    @Override
    public double custo() {
        return cafe.custo() + 1.50;
    }

    @Override
    public String getDescricao() {
        return cafe.getDescricao() + " com chocolate";
    }
}