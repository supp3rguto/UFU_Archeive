package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Canela extends Decorator{

    public Canela(Cafe cafe) {
        super(cafe);
    }

    @Override
    public double custo() {
        return cafe.custo() + 0.80;
    }

    @Override
    public String getDescricao() {
        return cafe.getDescricao() + " com canela";
    }
}