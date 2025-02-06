package factory;

public class Admin extends User {
    public Admin(String name) {
        this.name = name;
        this.role = "Administrador";
    }
}
