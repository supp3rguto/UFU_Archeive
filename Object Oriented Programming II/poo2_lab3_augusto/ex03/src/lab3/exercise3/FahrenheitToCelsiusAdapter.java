package lab3.exercise3;

public class FahrenheitToCelsiusAdapter implements TemperatureCelsius {
    private TemperatureFahrenheit fahrenheitTemperature;

    public FahrenheitToCelsiusAdapter(TemperatureFahrenheit fahrenheitTemperature) {
        this.fahrenheitTemperature = fahrenheitTemperature;
    }

    @Override
    public double getTemperatureInCelsius() {
        // Fórmula de conversão: (F - 32) * 5/9 = C
        return (fahrenheitTemperature.getTemperatureInFahrenheit() - 32) * 5 / 9;
    }
}
