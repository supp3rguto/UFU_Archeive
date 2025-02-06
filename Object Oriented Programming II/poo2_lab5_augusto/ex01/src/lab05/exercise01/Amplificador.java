package lab05.exercise01;
/**
 *
 * @author augusto
 */
public class Amplificador {
    public void ligar(){
        System.out.println("Amplificador ligado");
    }

    public void desligar(){
        System.out.println("Amplificador desligado");
    }

    public void ajustarVolume(int volume){
        System.out.println("Amplificador: volume: "+volume);
    }
}