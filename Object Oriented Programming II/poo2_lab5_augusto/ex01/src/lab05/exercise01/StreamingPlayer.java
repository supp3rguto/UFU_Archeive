package lab05.exercise01;
/**
 *
 * @author augusto
 */
public class StreamingPlayer {
    public void ligar(){
        System.out.println("Player ligado");
    }

    public void desligar(){
        System.out.println("Player desligado");
    }

    public void play(String filme){
        System.out.println("Você está assistindo: "+filme);
    }
}