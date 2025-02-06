package lab3.exercise02;

public class AdapterCalcDecimal implements Calculadora{

    private Decimal decimal;

    public AdapterCalcDecimal(Decimal decimal) {
        this.decimal = decimal;
    }
    
    @Override
    public String somar(String a, String b) {
        int numA = Integer.parseInt(a);
        int numB = Integer.parseInt(b);
        int resultado = decimal.somar(numA, numB);
        return Integer.toString(resultado);
    }

    @Override
    public String subtrair(String a, String b) {
         int numA = Integer.parseInt(a);
         int numB = Integer.parseInt(b);
         int resultado = decimal.subtrair(numA, numB);
         return Integer.toString(resultado);
    }
    
    @Override
    public String multiplicar(String a, String b) {
        
         int numA = Integer.parseInt(a);
         int numB = Integer.parseInt(b);
         int resultado = decimal.multiplicar(numA, numB);
         return Integer.toString(resultado);
    }
    
}
