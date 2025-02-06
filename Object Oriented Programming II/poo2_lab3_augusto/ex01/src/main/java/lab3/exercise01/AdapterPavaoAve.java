package lab3.exercise01;
/**
 *
 * @author augusto
 */
public class AdapterPavaoAve implements Ave{

    public Pavao pavao;

    public AdapterPavaoAve(Pavao pavao){
        this.pavao = pavao;
    }

    @Override
    public void EmitirSom() {
        pavao.cantar();
    }

    @Override
    public void Voar() {
        System.out.println("Pavao não sabe voar");
    }
}

