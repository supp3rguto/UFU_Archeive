package decorator;

public class CertificateDecorator extends CourseDecorator {
    public CertificateDecorator(Course course) {
        super(course);
    }

    @Override
    public String getDescription() {
        return course.getDescription() + " com Certificado";
    }

    @Override
    public double getPrice() {
        return course.getPrice() + 50.0;
    }
}
