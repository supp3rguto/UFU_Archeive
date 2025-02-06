package interfacesegregation.correct;

public class Penguin implements EatingBird, SleepingBird {

    public void eat() {
        System.out.println("PPinguin esta comendo.");
    }

    public void sleep() {
        System.out.println("Pinguin esta dormindo.");
    }
}