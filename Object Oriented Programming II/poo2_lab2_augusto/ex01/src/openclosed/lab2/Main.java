package openclosed.lab2;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("Escolha uma opção:");
            System.out.println("1. Construir celular");
            System.out.println("0. Sair");

            System.out.print("Opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o fabricante do celular (Apple ou Samsung): ");
                    String fabricanteDesejado = scanner.nextLine().toLowerCase();

                    System.out.print("Digite o modelo do celular: ");
                    String modeloDesejado = scanner.nextLine();

                    FabricanteCelular fabricante = FabricanteCelularSingleton.getInstance(fabricanteDesejado);
                    if (fabricante != null) {
                        Celular celular = fabricante.constroiCelular(modeloDesejado);
                        if (celular != null) {
                            System.out.println("Você tem um " + celular.getModelo());
                            celular.tiraFoto();
                            celular.fazLigacao();
                        } else {
                            System.out.println("Modelo desconhecido.");
                        }
                    } else {
                        System.out.println("Fabricante desconhecido.");
                    }
                    break;

                case 0:
                    System.out.println("Saindo do programa.");
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 0);
    }
}
