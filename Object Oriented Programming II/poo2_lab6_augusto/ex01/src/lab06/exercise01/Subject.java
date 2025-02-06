package lab06.exercise01;
/*
 *
 * @author augusto
 */
public interface Subject {
    public void addObserver(Observer observador);
    public void removeObserver(Observer observador);
    public void notifyObserver();
    public void setUmidade(double umidade);
}