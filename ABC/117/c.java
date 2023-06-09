import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numPieces = scanner.nextInt();
        int numTargets = scanner.nextInt();

        int[] targets = new int[numTargets];
        for (int i = 0; i < numTargets; ++i) {
            targets[i] = scanner.nextInt();
        }

        Arrays.sort(targets);

        int[] distances = new int[numTargets - 1];
        for (int i = 0; i < numTargets - 1; ++i) {
            distances[i] = targets[i + 1] - targets[i];
        }

        Arrays.sort(distances);

        long minMoves = 0;
        for (int i = 0; i < numTargets - numPieces; ++i) {
            minMoves += distances[i];
        }

        System.out.println(minMoves);
    }
}
