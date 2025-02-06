package strategy;

public interface ScoringStrategy {
    int calculateScore(int correctAnswers, int totalQuestions);
}
