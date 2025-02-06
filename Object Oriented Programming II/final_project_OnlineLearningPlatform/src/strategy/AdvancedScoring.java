package strategy;

public class AdvancedScoring implements ScoringStrategy {
    @Override
    public int calculateScore(int correctAnswers, int totalQuestions) {
        return (int) ((double) correctAnswers / totalQuestions * 100);
    }
}
