import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();

        String[] strings = new String[n];
        for (int i = 0; i < n; ++i) {
            strings[i] = scanner.nextLine();
        }

        int maxOccurrence = 0;
        for (int bit = 0; bit < (1 << n); ++bit) {
            int[] charCount = new int[26];
            for (int idx = 0; idx < n; ++idx) {
                if (((bit >> idx) & 1) == 1) {
                    for (char c : strings[idx].toCharArray()) {
                        charCount[c - 'a']++;
                    }
                }
            }
            int currentOccurrence = 0;
            for (int count : charCount) {
                if (count == k) currentOccurrence++;
            }
            maxOccurrence = Math.max(maxOccurrence, currentOccurrence);
        }
        System.out.println(maxOccurrence);
    }
}
