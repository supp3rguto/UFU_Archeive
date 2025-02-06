package strategy;

public class SimpleScoring implements ScoringStrategy {
    @Override
    public int calculateScore(int correctAnswers, int totalQuestions) {
        return correctAnswers * 10;
    }
}
