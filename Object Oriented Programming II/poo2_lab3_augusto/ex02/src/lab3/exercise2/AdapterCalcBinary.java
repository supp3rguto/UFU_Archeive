package lab3.exercise02;

public class AdapterCalcBinary implements Calculadora{

    public AdapterCalcBinary(Binaria binaria) {
    }

    @Override
    public String somar(String a, String b) {
        int numA = Integer.parseInt(a);
        int numB = Integer.parseInt(b);
        int resultado = numA + numB;
        return Integer.toBinaryString(resultado);
    }

    @Override
    public String subtrair(String a, String b) {
        int numA = Integer.parseInt(a);
        int numB = Integer.parseInt(b);
        int resultado = numA - numB;
        return Integer.toBinaryString(resultado);
    }

    @Override
    public String multiplicar(String a, String b) {
        return "Não é possível executar multiplicação em binário!";
    }


}
