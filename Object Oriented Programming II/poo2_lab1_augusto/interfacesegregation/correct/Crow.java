package interfacesegregation.correct;

public class Crow implements EatingBird, SleepingBird, FlyingBird {

    public void eat() {
        System.out.println("Corvo esta comendo.");
    }

    public void sleep() {
        System.out.println("Corvo esta dormindo.");
    }

    public void fly() {
        System.out.println("Corvo esta voando.");
    }

}