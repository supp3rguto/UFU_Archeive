package lab04.exercise01;
/**
 *
 * @author augusto
 */
public class MassaEspessaPizza implements Pizza{

    @Override
    public double custo() {
        return 90.00;
    }

    @Override
    public String getDescricao() {
        return "Massa Pizza: Espessa";
    }

}