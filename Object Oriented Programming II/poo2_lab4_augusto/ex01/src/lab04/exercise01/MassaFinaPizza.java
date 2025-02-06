package lab04.exercise01;
/**
 *
 * @author augusto
 */
public class MassaFinaPizza implements Pizza {

    @Override
    public double custo() {
        return 70.00;
    }

    @Override
    public String getDescricao() {
        return "Massa Pizza: Fina";
    }

}