package lab3.exercise01;
/**
 *
 * @author augusto
 */
public class AdapterPatoAve implements Ave{
    private Pato pato;

    public AdapterPatoAve(Pato pato){
        this.pato = pato;
    }

    @Override
    public void EmitirSom() {
        pato.grasnar();
    }

    @Override
    public void Voar() {
        pato.voar();
    }
}
