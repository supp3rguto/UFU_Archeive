package lab04.exercise02;
/**
 *
 @author augusto
 */
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do{
            System.out.println("Escolha uma opcao:");
            System.out.println("1. Cafe Espresso");
            System.out.println("2. Cafe Descafeinado");
            System.out.println("0. Sair");
            opcao = scanner.nextInt();

            switch(opcao){
                case 1:
                    criarCafe(new Espresso());
                    break;
                case 2:
                    criarCafe(new Decaf());
                    break;
                case 0:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opcao Invalida!");
            }


        }while(opcao != 0);
        scanner.close();
    }

    private static void criarCafe(Cafe cafe){
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do{
            System.out.println("Escolha um ingrediente:");
            System.out.println("1. Leite");
            System.out.println("2. Canela");
            System.out.println("3. Chocolate");
            System.out.println("0. Voltar");
            opcao = scanner.nextInt();

            switch(opcao){
                case 1:
                    cafe = new Leite(cafe);
                    break;
                case 2:
                    cafe = new Canela(cafe);
                    break;
                case 3:
                    cafe = new Chocolate(cafe);
                    break;
                case 0:
                    System.out.println("Voltando...");
                    break;
                default:
                    System.out.println("Opcao Invalida!");
            }
        }while(opcao != 0);

        System.out.println("Custo total do café: " + cafe.custo());
        System.out.println("Descricao do café: " + cafe.getDescricao());
    }
}