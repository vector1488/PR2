import java.util.Scanner;

public class Modules {
    private static int modInverse(int a, int m) {
        int m0 = m, y = 0, x = 1;
        if (m == 1) return 0;
        if (a == m) return 1;

        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return (a == 1) ? x : -1;
    }

    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.println("c^-1 mod m = d");
        System.out.print("Введите значения c и m: ");
        int c = sc.nextInt(), m = sc.nextInt();
        int inv = modInverse(c, m);
        if (inv == -1) {
            System.out.println("Обратного элемента для " + c + " mod " + m + " не существует!");
        } else {
            System.out.println("Обратный элемент = " + inv);
            System.out.println("Проверка: " + (c * inv) % m);
        }
    }
}
