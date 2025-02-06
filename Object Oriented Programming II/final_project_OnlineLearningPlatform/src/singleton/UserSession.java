package singleton;

public class UserSession {
    private static UserSession instance;
    private String currentUser;

    private UserSession() {}

    public static UserSession getInstance() {
        if (instance == null) {
            instance = new UserSession();
        }
        return instance;
    }

    public void login(String username) {
        this.currentUser = username;
        System.out.println("Usuário " + username + " logado com sucesso!");
    }

    public String getCurrentUser() {
        return currentUser;
    }
}
