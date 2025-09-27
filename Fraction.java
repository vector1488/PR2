import java.util.*;

public class Fraction {
    private static List<Integer> continuedFraction(int p, int q, int[] m) {
        List<Integer> cf = new ArrayList<>();
        while (q != 0) {
            int a = p / q;
            cf.add(a);
            int r = p % q;
            p = q;
            q = r;
        }
        m[0] = p;
        return cf;
    }

    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите значения множителей a и b:");
        int p = sc.nextInt(), q = sc.nextInt();
        int[] m = new int[1];
        List<Integer> cf = continuedFraction(p, q, m);
        System.out.print(p + "/" + q + " = [");
        for (int i = 0; i < cf.size(); i++) {
            System.out.print(cf.get(i));
            if (i + 1 < cf.size()) System.out.print(";");
        }
        System.out.println("]");
        System.out.println("НОД: " + m[0]);
    }
}
