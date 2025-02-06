package lab3.exercise01;
/**
 *
 * @author augusto
 */
public class PatoDomestico implements Pato{

    @Override
    public void grasnar() {
        System.out.println("O Pato Domestico está grasnando");
    }

    @Override
    public void voar() {
        System.out.println("O Pato Domestico está voando");

    }
}
