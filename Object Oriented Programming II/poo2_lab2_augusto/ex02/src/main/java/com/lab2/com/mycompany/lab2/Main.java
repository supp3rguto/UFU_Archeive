package com.mycompany.lab2;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Com o Singleton, pego a instância das fábricas tanto Toyota quanto Honda
        Toyota toyotaFactory = Toyota.getInstance();
        Honda hondaFactory = Honda.getInstance();

        Scanner scanner = new Scanner(System.in);
        int op;

        do {
            System.out.println("Escolha uma opção");
            System.out.println("1. Escolher carro");
            System.out.println("0. Sair do programa");

            System.out.print("Opção: ");
            op = scanner.nextInt();
            scanner.nextLine(); // Consumir a nova linha deixada pelo nextInt()

            switch (op) {
                case 1:
                    System.out.println("Escolha entre Toyota ou Honda: ");
                    String toyotaOrHonda = scanner.nextLine().toLowerCase();

                    IVehicle vehicle = null;
                    String modeloDesejado = "";

                    switch (toyotaOrHonda) {
                        case "toyota":
                            System.out.println("::Toyota:: Qual você quer?");
                            System.out.println("1. Hilux");
                            System.out.println("2. Corolla");
                            System.out.println("3. Etios");
                            System.out.print("Opção: ");
                            modeloDesejado = scanner.nextLine().toLowerCase();
                            vehicle = toyotaFactory.makeVehicle(modeloDesejado);
                            break;

                        case "honda":
                            System.out.println("::Honda:: Qual você quer?");
                            System.out.println("1. Civic");
                            System.out.println("2. City");
                            System.out.println("3. Fit");
                            System.out.print("Opção: ");
                            modeloDesejado = scanner.nextLine().toLowerCase();
                            vehicle = hondaFactory.makeVehicle(modeloDesejado);
                            break;

                        default:
                            System.out.println("Opção inválida.");
                    }

                    if (vehicle != null) {
                        System.out.println("Você tem um " + modeloDesejado);
                        vehicle.start();
                        vehicle.stop();
                        vehicle.drive();
                    } else {
                        System.out.println("Modelo não encontrado.");
                    }
                    break;

                case 0:
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida.");
            }
        } while (op != 0);

        scanner.close();
    }
}
