package lab07.exercise02;
/*
 *
 * @author augusto
 */
public class LojaFisica extends PedidoTemplate{
    public LojaFisica(int quantidadeItens, double valorUnitario, String formaPagamento) {
        super(quantidadeItens, valorUnitario, formaPagamento);
    }

    @Override
    void processarPagamento() {
        System.out.println("Pagamento "+formaPagamento+" de quantidade "+quantidadeItens+" e valor unitario R$ "+valorUnitario);
    }

    @Override
    void decidirEntrega() {
        System.out.println("Nao existe entrega");
    }

}