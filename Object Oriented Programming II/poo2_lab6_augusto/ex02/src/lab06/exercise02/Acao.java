package lab06.exercise02;
/*
 *
 * @author augusto
 */
import java.util.ArrayList;
import java.util.List;

public class Acao implements Observable{
    private String nome;
    private double preco;
    private List<Observer> investidores;

    public Acao(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
        this.investidores = new ArrayList<>();
    }

    public void setPreco(double preco) {
        if (this.preco != preco) {
            this.preco = preco;
            notifyObservers(preco);
        }
    }

    @Override
    public void addObserver(Observer observer) {
        investidores.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        investidores.remove(observer);
    }

    @Override
    public void notifyObservers(double price) {
        for (Observer observer : investidores) {
            observer.update(price);
        }
    }
}