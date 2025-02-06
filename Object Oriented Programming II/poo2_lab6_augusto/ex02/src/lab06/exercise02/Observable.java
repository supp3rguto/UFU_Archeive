package lab06.exercise02;
/*
 *
 * @author augusto
 */
public interface Observable {
    void addObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers(double price);
}