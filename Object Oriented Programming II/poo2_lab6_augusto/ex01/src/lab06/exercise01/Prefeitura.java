package lab06.exercise01;
/*
 *
 * @author augusto
 */
public class Prefeitura implements Observer{

    @Override
    public void update(double temp, double velocidade, double umidade) {
        System.out.println("Prefeitura: foi encaminhado o alerta climático");
    }
}