# Padrão Proxy no Tema de Videogame

## Problema Proposto

Criar um jogo em que temos um personagem com informações detalhadas que são carregadas apenas quando o jogador realmente precisa ver essas informações (por exemplo, ao abrir uma tela de status). **Proxy**: usado para atrasar o carregamento completo das informações até que elas sejam solicitadas, otimizando o uso de recursos.

## Estrutura

- **Interface `Character`:** Define os métodos para acessar os dados do personagem.
- **Classe `RealCharacter`:** Representa o personagem real, com todos os dados detalhados (nome, nível, habilidades). Estes dados serão carregados de forma demorada.
- **Classe `CharacterProxy`:** Um proxy que controla o acesso ao objeto `RealCharacter`. Ele carregará os dados apenas quando forem solicitados pela primeira vez.

## Explicação do Código

1. **Interface `Character`:** Define o contrato que tanto o proxy quanto o objeto real devem seguir, garantindo que o proxy e o personagem real possam ser tratados da mesma maneira.
2. **Classe `RealCharacter`:** Simula o carregamento de dados demorados de um personagem (como suas habilidades e nível). Este carregamento só ocorre quando o método `displayInfo()` é chamado pela primeira vez.
3. **Classe `CharacterProxy`:** Atua como intermediária, retardando o carregamento dos dados do personagem até que seja realmente necessário. Isso economiza recursos, especialmente em jogos que possuem muitos personagens, mas nem todos os dados precisam ser carregados de imediato.
4. **Classe `Game`:** Demonstra o uso do Proxy. Primeiramente, acessamos o nome do personagem sem carregar os dados completos, e só quando realmente precisamos das informações detalhadas, o proxy carrega o personagem.

## Funcionamento

Quando o código é executado, você verá que os dados do personagem são carregados apenas quando as informações detalhadas são solicitadas. Antes disso, o proxy retorna apenas o nome do personagem sem carregar tudo.
