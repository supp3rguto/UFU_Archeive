package lab05.exercise03;
/**
 *
 @author augusto
 */
public class Game {
    public static void main(String[] args) {
        // Criamos um proxy para o personagem
        Character player1 = new CharacterProxy("Rider");
        Character player2 = new CharacterProxy("Cleric");

        // O personagem só é carregado quando suas informações são solicitadas
        System.out.println("Acessando nome do personagem 1 sem carregar os dados completos:");
        System.out.println(player1.getName());

        System.out.println("\nCarregando informações detalhadas do personagem 1:");
        player1.displayInfo();  // Nesse momento, o proxy carrega os dados reais

        System.out.println("\nAcessando nome do personagem 2 sem carregar os dados completos:");
        System.out.println(player2.getName());

        System.out.println("\nCarregando informações detalhadas do personagem 2:");
        player2.displayInfo();  // Aqui o segundo personagem é carregado
    }
}