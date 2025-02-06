package lab05.exercise01;
/**
 *
 * @author augusto
 */
public class CinametecaFachada {
    private Amplificador amplificador;
    private Telao telao;
    private Luzes luzes;
    private Projetor projetor;
    private MaquinaPipoca maquinaPipoca;
    private StreamingPlayer player;

    public CinametecaFachada() {
        this.amplificador = new Amplificador();
        this.telao = new Telao();
        this.luzes = new Luzes();
        this.projetor = new Projetor();
        this.maquinaPipoca = new MaquinaPipoca();
        this.player = new StreamingPlayer();
    }

    public void iniciarFilme(String filme) {
        System.out.println("Iniciando o filme...");
        maquinaPipoca.ligar();
        maquinaPipoca.rebentaPipoca();
        luzes.desligaLuz();
        telao.desceTelao();
        projetor.ligar();
        amplificador.ligar();
        amplificador.ajustarVolume(12);
        player.ligar();
        player.play(filme);
        System.out.println("Filme iniciado!");
    }

    public void encerrarFilme() {
        System.out.println("Encerrando o filme...");
        player.desligar();
        amplificador.desligar();
        projetor.desliga();
        telao.sobeTelao();
        luzes.ligaLuz();
        maquinaPipoca.desliga();
        System.out.println("Filme encerrado!");
    }
}
