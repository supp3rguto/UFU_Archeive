package decorator;

public abstract class CourseDecorator implements Course {
    protected Course course;

    public CourseDecorator(Course course) {
        this.course = course;
    }

    @Override
    public String getDescription() {
        return course.getDescription();
    }

    @Override
    public double getPrice() {
        return course.getPrice();
    }
}
