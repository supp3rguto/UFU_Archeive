package factory;

public class UserFactory {
    public static User createUser(String type, String name) {
        switch (type.toLowerCase()) {
            case "estudante":
                return new Student(name);
            case "professor":
                return new Teacher(name);
            case "diretor":
                return new Admin(name);
            default:
                throw new IllegalArgumentException("Tipo de usuário não suportado.");
        }
    }
}
