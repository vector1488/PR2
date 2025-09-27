import java.util.Scanner;

public class Extevklid {
    private static int[] extendedGcd(int a, int b) {
        int x1 = a, y1 = b;
        int x2 = 1, y2 = 0;
        int x3 = 0, y3 = 1;

        while (y1 != 0) {
            int q = x1 / y1;
            int t1 = x1 % y1;
            int t2 = x2 - q * y2;
            int t3 = x3 - q * y3;

            x1 = y1; x2 = y2; x3 = y3;
            y1 = t1; y2 = t2; y3 = t3;
        }
        return new int[]{x1, x2, x3}; // gcd, u, v
    }

    private static int findD(int m, int n) {
        int[] r = extendedGcd(m, n);
        int gcd = r[0], x = r[1];
        if (gcd != 1) throw new RuntimeException("Обратного элемента не существует");
        return (x % n + n) % n;
    }

    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите c и m (для уравнения c*d mod m = 1):");
        int c = sc.nextInt(), m = sc.nextInt();
        try {
            int d = findD(c, m);
            System.out.println("Обратный элемент d = " + d);
            System.out.println("Проверка: " + (c * d) % m);
        } catch (RuntimeException e) {
            System.out.println("Ошибка: " + e.getMessage());
        }
    }
}
