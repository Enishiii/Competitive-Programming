import java.util.*;
import java.math.*;

public class Main {
    static BigInteger sumTillN(BigInteger n) {
        return (n.multiply(n.add(BigInteger.ONE))).divide(BigInteger.valueOf(2));
    }

    static BigInteger sumOfMultiplesTillN(BigInteger n, BigInteger a) {
        return sumTillN(n.divide(a)).multiply(a);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger n = scanner.nextBigInteger();
        BigInteger a = scanner.nextBigInteger();
        BigInteger b = scanner.nextBigInteger();
        scanner.close();

        BigInteger lcm = a.multiply(b).divide(a.gcd(b));
        BigInteger ans = sumTillN(n);

        ans = ans.subtract(sumOfMultiplesTillN(n, a));
        ans = ans.subtract(sumOfMultiplesTillN(n, b));
        ans = ans.add(sumOfMultiplesTillN(n, lcm));

        System.out.println(ans.toString());
    }
}
