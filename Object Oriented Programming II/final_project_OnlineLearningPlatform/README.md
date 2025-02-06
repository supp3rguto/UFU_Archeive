# OnlineLearningPlatform

![Online Learning Plataform - Logo](https://github.com/supp3rguto/OnlineLearningPlatform/blob/main/olplogo.png)

## 1. Introdução

### O que é o sistema?
O *OnlineLearningPlatform* é um sistema de ensino online desenvolvido em Java. Ele permite que diferentes tipos de usuários (estudantes, professores e administradores) façam login, visualizem cursos e gerenciem atividades específicas relacionadas ao seu papel. O sistema também inclui funcionalidades como notificações de eventos e cálculo de pontuações.

### Motivação
A motivação para desenvolver este software surgiu da necessidade de criar uma aplicação modular e extensível que demonstre a utilização de diversos padrões de projeto. O projeto foi escolhido para ajudar a ilustrar como os padrões de projeto e princípios de design podem ser aplicados para construir um software robusto, fácil de manter e escalável.

---

## 2. Padrões de Projeto

### Singleton
*Descrição:* O padrão *Singleton* garante que apenas uma instância da classe UserSession exista durante a execução do programa. Isso é útil para gerenciar o estado da sessão do usuário de forma centralizada.

```java
package singleton;

public class UserSession {
    private static UserSession instance;
    private String currentUser;

    private UserSession() {}

    public static UserSession getInstance() {
        if (instance == null) {
            instance = new UserSession(); // Criação única da instância
        }
        return instance;
    }

    public void login(String username) {
        this.currentUser = username;
        System.out.println("Usuário " + username + " logado com sucesso!");
    }

    public String getCurrentUser() {
        return currentUser;
    }
}
```

### Factory Method
*Descrição:* O *Factory Method* é utilizado para criar diferentes tipos de usuários (Student, Teacher, Admin). Ele permite a criação de objetos de forma flexível e desacoplada.

```java
package factory;

public class UserFactory {
    public static User createUser(String type, String name) {
        switch (type.toLowerCase()) {
            case "student":
                return new Student(name);
            case "teacher":
                return new Teacher(name);
            case "admin":
                return new Admin(name);
            default:
                throw new IllegalArgumentException("Tipo de usuário não suportado.");
        }
    }
}
```

### Strategy
*Descrição:* O padrão *Strategy* permite a troca de algoritmos de cálculo de pontuação sem alterar o código que os utiliza, promovendo a flexibilidade.

```java
package strategy;

public interface ScoringStrategy {
    int calculateScore(int correctAnswers, int totalQuestions);
}

package strategy;

public class AdvancedScoring implements ScoringStrategy {
    @Override
    public int calculateScore(int correctAnswers, int totalQuestions) {
        return (int) ((double) correctAnswers / totalQuestions * 100);
    }
}
```

### Decorator
*Descrição:* O *Decorator* permite que funcionalidades sejam adicionadas dinamicamente a um objeto, sem alterar sua estrutura original. Isso é útil para estender as funcionalidades de um curso.

```java
package decorator;

public class CertificateDecorator extends CourseDecorator {
    public CertificateDecorator(Course course) {
        super(course);
    }

    @Override
    public String getDescription() {
        return course.getDescription() + " com Certificado";
    }

    @Override
    public double getPrice() {
        return course.getPrice() + 50.0;
    }
}
```

### Observer
*Descrição:* O *Observer* permite que objetos sejam notificados sobre eventos em outro objeto. No sistema, NotificationService gerencia a lista de observadores e notifica sobre novos cursos ou eventos.

```java
package observer;

import java.util.ArrayList;
import java.util.List;

public class NotificationService {
    private List<Observer> observers = new ArrayList<>();

    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    public void notifyObservers(String message) {
        for (Observer observer : observers) {
            observer.update(message);
        }
    }
}
```
```java
package observer;

public class UserObserver implements Observer {
    private String name;

    public UserObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println("Notificação para " + name + ": " + message);
    }
}
```

---

## 3. Princípios de Projeto

### Princípio da Responsabilidade Única (SRP)
*Descrição*: Cada classe deve ter uma única responsabilidade bem definida. A classe UserSession é um exemplo, pois é responsável apenas por gerenciar a sessão do usuário.

```java
package singleton;

public class UserSession {
    private static UserSession instance;
    private String currentUser;

    // Única responsabilidade: gerenciar a sessão do usuário
}
```

### Princípio Aberto/Fechado (OCP)
*Descrição*: As classes devem ser abertas para extensão, mas fechadas para modificação. A UserFactory segue este princípio ao permitir a adição de novos tipos de usuários sem modificar seu código existente.

```java
package factory;

public class UserFactory {
    // A classe pode ser estendida para novos tipos de usuários sem modificar o código original
}
```

### Princípio da Substituição de Liskov (LSP)
*Descrição*: As subclasses devem ser substituíveis por suas superclasses. As implementações de ScoringStrategy seguem este princípio, pois podem substituir a interface sem problemas.

```java
package strategy;

public class AdvancedScoring implements ScoringStrategy {
    // Implementação substituível que mantém o comportamento esperado
}
```

### Princípio da Inversão de Dependência (DIP)
*Descrição*: O código deve depender de abstrações, não de implementações concretas. No projeto, OnlineLearningPlatform depende da interface ScoringStrategy, garantindo a flexibilidade de usar diferentes estratégias.

```java
package main;

import strategy.ScoringStrategy;
import strategy.AdvancedScoring;

public class OnlineLearningPlatform {
    ScoringStrategy scoringStrategy = new AdvancedScoring(); // Dependência de abstração
}
```

---

## 5. Conclusão

### Lições aprendidas
O desenvolvimento do *OnlineLearningPlatform* proporcionou uma compreensão mais profunda da importância de aplicar padrões de projeto para criar um software modular e extensível. A aplicação dos princípios de design resultou em um código que é fácil de manter, ler e escalar.

### Dificuldades encontradas
As principais dificuldades encontradas foram integrar diferentes padrões de projeto de forma coesa e garantir que o código mantivesse a simplicidade, sem se tornar excessivamente complexo.

---

## 6. Autores

- Augusto Ortigoso Barbosa
- Felype Henrique Hilário de Araujo
- Luís Gustavo Silva
- Matheus Seite Vicente Matsuoka
