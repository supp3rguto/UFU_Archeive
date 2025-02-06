package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Decorator implements Cafe{

    protected Cafe cafe;

    public Decorator(Cafe cafe) {
        this.cafe = cafe;
    }

    @Override
    public double custo() {
        return cafe.custo();
    }

    @Override
    public String getDescricao() {
        return cafe.getDescricao();
    }
}