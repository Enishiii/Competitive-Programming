import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num_strings = scanner.nextInt();
        int length_strings = scanner.nextInt();

        String[] strings = new String[num_strings];

        for (int i = 0; i < num_strings; ++i) {
            strings[i] = scanner.next();
        }

        Arrays.sort(strings);

        StringBuilder sb = new StringBuilder();
        for (String str : strings) {
            sb.append(str);
        }

        System.out.println(sb.toString());
    }
}
