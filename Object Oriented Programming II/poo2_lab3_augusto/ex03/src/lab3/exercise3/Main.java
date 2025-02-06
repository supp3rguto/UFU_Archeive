package lab3.exercise3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Insira a temperatura em Fahrenheit: ");
        double temperatureInFahrenheit = scanner.nextDouble();

        // Criar o sistema Fahrenheit com o dado inserido
        TemperatureFahrenheit fahrenheitTemperature = new TemperatureFahrenheit(temperatureInFahrenheit);

        // Adaptar a temperatura de Fahrenheit para Celsius
        TemperatureCelsius celsiusTemperature = new FahrenheitToCelsiusAdapter(fahrenheitTemperature);

        // Exibir a temperatura convertida
        System.out.printf("Temperatura em Celsius: %.2f%n", celsiusTemperature.getTemperatureInCelsius());

        scanner.close();
    }
}
