package decorator;

public class BasicCourse implements Course {
    @Override
    public String getDescription() {
        return "Curso básico";
    }

    @Override
    public double getPrice() {
        return 100.0;
    }
}
