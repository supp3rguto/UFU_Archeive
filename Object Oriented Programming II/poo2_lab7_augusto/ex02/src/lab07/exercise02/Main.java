package lab07.exercise02;
/*
 *
 * @author augusto
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("\nPedido Loja Online:");
        PedidoTemplate online = new LojaOnline(1,2.5,"Online");
        online.ProcessarPedido();

        System.out.println("\nPedido Loja Fisica:");
        PedidoTemplate naloja = new LojaFisica(4,4.1,"Local");
        naloja.ProcessarPedido();

        System.out.println("\nPedido Por Criptomoeda:");
        PedidoTemplate criptomoeda = new Criptomoeda(7,5.5,"Criptomoeda");
        criptomoeda.ProcessarPedido();

    }
}