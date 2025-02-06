/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package openclosed;


/**
 *
 * @author fabiola
 */
public class OpenClosed {
    
    public OpenClosed(){
        doIncorrectImplementation();
        doCorrectImplementation();
    }
    
    public void doIncorrectImplementation(){
        
        /**
         * Aqui temos classes Rectangle e Circle que utilizam a classe GeometryOperation para calculo da area
         */
        openclosed.incorrect.Rectangle rectangle = new openclosed.incorrect.Rectangle(4,3);
        openclosed.incorrect.Circle circle = new openclosed.incorrect.Circle(5);
        
        /**
         * Toda vez que uma nova forma geometrica eh adicionada, precisaremos de uma nova logica para calculo da area
         * Como precisaremos mudar o codigo existente (GeometryOperation), essa abordagem fere o Principio do Aberto-Fechado
         */
        openclosed.incorrect.GeometryOperation op = new openclosed.incorrect.GeometryOperation();
        System.out.println("Area do retangulo -> " + op.getArea(rectangle));
        System.out.println("Area do circulo -> " + op.getArea(circle));
    }
    
    public void doCorrectImplementation(){
        
        /**
         * Adicione aqui seu código refatorado com referências a métodos e classes contidas no pacote openclosed.correct
         * Como ficaria a adicao da forma geometrica Triangulo?
         */
        
        
    }
    
    public static void main(String [] args ) {
        OpenClosed opClo = new OpenClosed();
      
    }
    
}
