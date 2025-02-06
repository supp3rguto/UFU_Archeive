package main;

import singleton.UserSession;
import factory.User;
import factory.UserFactory;
import strategy.ScoringStrategy;
import strategy.AdvancedScoring;
import decorator.BasicCourse;
import decorator.CertificateDecorator;
import decorator.Course;
import admin.AdminFunctions;

import java.util.Scanner;

public class OnlineLearningPlatform {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UserSession session = UserSession.getInstance();

        System.out.println("Bem-vindo à Plataforma de Ensino Online!");
        System.out.print("Digite seu nome de usuário para fazer login: ");
        String username = scanner.nextLine();
        session.login(username);

        System.out.print("Digite seu tipo de usuário (estudante/professor/diretor): ");
        String userType = scanner.nextLine();
        User user;
        try {
            user = UserFactory.createUser(userType, username);
            System.out.println("Usuário criado: " + user.getName() + ", Papel: " + user.getRole());
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return;
        }

        switch (user.getRole().toLowerCase()) {
            case "estudante":
                System.out.println("\n--- Funcionalidades do Estudante ---");
                visualizarCurso();
                calcularPontuacao();
                break;

            case "professor":
                System.out.println("\n--- Funcionalidades do Professor ---");
                gerenciarCursos();
                break;

            case "administrador":
                System.out.println("\n--- Funcionalidades do Administrador ---");
                AdminFunctions adminFunctions = new AdminFunctions();
                adminFunctions.manageUsers();
                adminFunctions.manageCourses();
                adminFunctions.generateReports();
                break;

            default:
                System.out.println("Papel do usuário não reconhecido.");
                break;
        }
    }

    private static void visualizarCurso() {
        Course basicCourse = new BasicCourse();
        Course certifiedCourse = new CertificateDecorator(basicCourse);
        System.out.println("Descrição do curso: " + certifiedCourse.getDescription());
        System.out.println("Preço do curso: " + certifiedCourse.getPrice());
    }

    private static void calcularPontuacao() {
        ScoringStrategy scoringStrategy = new AdvancedScoring();
        int score = scoringStrategy.calculateScore(8, 10);
        System.out.println("Pontuação calculada: " + score);
    }

    private static void gerenciarCursos() {
        System.out.println("Criando ou gerenciando cursos...");
    }
}
