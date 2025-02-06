package lab06.exercise01;
/*
 *
 * @author augusto
 */
public class Aeroporto implements Observer{

    @Override
    public void update(double temp, double velocidade, double umidade) {
        System.out.println("Aeroporto: foi encaminhado o alerta climático");
    }
}