package lab04.exercise02;
/**
 *
 @author augusto
 */
public class Leite extends Decorator{

    public Leite(Cafe cafe) {
        super(cafe);
    }

    @Override
    public double custo() {
        return cafe.custo() + 0.50;
    }

    @Override
    public String getDescricao() {
        return cafe.getDescricao() + " com leite";
    }
}