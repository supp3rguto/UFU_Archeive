package lab3.exercise02;

import java.util.Scanner;

public class Main {

   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      int opcao;

      Decimal dc = new CalculadoraDecimal();
      Calculadora dcCalculadora = new AdapterCalcDecimal(dc);

      Binaria bn = new CalculadoraBinaria();
      Calculadora bnCalculadora = new AdapterCalcBinary(bn);

      do {
         System.out.println("Escolha o tipo de cálculo:");
         System.out.println("1. Decimal");
         System.out.println("2. Binário");
         System.out.println("0. Sair");
         opcao = scanner.nextInt();
         scanner.nextLine(); // Consumir a linha

         if (opcao == 1 || opcao == 2) {
            Calculadora calculadoraSelecionada = (opcao == 1) ? dcCalculadora : bnCalculadora;

            System.out.println("Escolha a operação:");
            System.out.println("1. Somar");
            System.out.println("2. Subtrair");
            System.out.println("3. Multiplicar");
            int operacao = scanner.nextInt();
            scanner.nextLine(); // Consumir a linha

            System.out.print("Digite o primeiro valor: ");
            String valor1 = scanner.nextLine();

            System.out.print("Digite o segundo valor: ");
            String valor2 = scanner.nextLine();

            switch (operacao) {
               case 1:
                  System.out.println("Resultado da soma: " + calculadoraSelecionada.somar(valor1, valor2));
                  break;
               case 2:
                  System.out.println("Resultado da subtração: " + calculadoraSelecionada.subtrair(valor1, valor2));
                  break;
               case 3:
                  System.out.println(calculadoraSelecionada.multiplicar(valor1, valor2));
                  break;
               default:
                  System.out.println("Opção inválida.");
            }
         } else if (opcao != 0) {
            System.out.println("Opção inválida.");
         }
      } while (opcao != 0);

      System.out.println("Programa encerrado.");
      scanner.close();
   }
}
