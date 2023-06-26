import java.util.*;

public class Main {
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = sc.nextInt();

        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = gcd(ans, a[i]);
        }

        System.out.println(ans);
    }
}
