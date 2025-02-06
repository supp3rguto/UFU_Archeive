package lab05.exercise03;
/**
 *
 @author augusto
 */
class CharacterProxy implements Character {
    private RealCharacter realCharacter;
    private String name;

    public CharacterProxy(String name) {
        this.name = name;
    }

    // Acesso controlado ao objeto RealCharacter. Só carrega o objeto quando necessário
    @Override
    public void displayInfo() {
        if (realCharacter == null) {
            realCharacter = new RealCharacter(name);
        }
        realCharacter.displayInfo();
    }

    @Override
    public String getName() {
        return name;
    }
}