package lab06.exercise02;

public class CarroFachada {
    private CintoDeSegurança cintodeseguranca = new CintoDeSegurança();
    private Farol farol = new Farol();
    private Motor motor = new Motor();
    private Porta porta = new Porta();
    private Radio radio = new Radio();


    public void iniciaCorrida(){
        motor.ligar();
        porta.trancarPorta();
        cintodeseguranca.travarCintoDeSeguranca();
        farol.acenderFarol();
        radio.ligar();
        radio.sintonizar("Antena 1 - 94,7");
    }

    public void finalizaCorrida(){
        motor.desligar();
        porta.destrancarPorta();
        cintodeseguranca.destravarCintoDeSeguranca();
        farol.apagarFarol();
        radio.desligar();
    }
}