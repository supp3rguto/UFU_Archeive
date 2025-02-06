package lab05.exercise03;
/**
 *
 @author augusto
 */
class RealCharacter implements Character {
    private String name;
    private int level;
    private String[] abilities;

    public RealCharacter(String name) {
        this.name = name;
        loadCharacterData();  // Simula o carregamento demorado dos dados
    }

    // Simula o carregamento dos dados demorados do personagem (ex: habilidades)
    private void loadCharacterData() {
        System.out.println("Carregando dados do personagem " + name + "...");
        try {
            Thread.sleep(3000);  // Simula um tempo de carregamento
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.level = 10;  // Nível fictício
        this.abilities = new String[] {"Ataque", "Defesa", "Magia"};
    }

    // Exibe as informações completas do personagem
    @Override
    public void displayInfo() {
        System.out.println("Personagem: " + name);
        System.out.println("Nível: " + level);
        System.out.println("Habilidades: ");
        for (String ability : abilities) {
            System.out.println("- " + ability);
        }
    }

    @Override
    public String getName() {
        return name;
    }
}