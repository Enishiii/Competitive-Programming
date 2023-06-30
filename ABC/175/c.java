import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long x = scanner.nextLong();
        long k = scanner.nextLong();
        long d = scanner.nextLong();

        x = Math.abs(x);

        long stepsToZero = Math.min(k, x / d);

        k -= stepsToZero;
        x -= stepsToZero * d;

        if (k % 2 == 0) {
            System.out.println(x);
        } else {
            System.out.println(d - x);
        }

        scanner.close();
    }
}
