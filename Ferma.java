import java.util.Scanner;

public class Ferma {
    private static long powerMod(long a, long b, long c) {
        long result = 1;
        a = a % c;
        while (b > 0) {
            if ((b & 1) == 1) result = (result * a) % c;
            a = (a * a) % c;
            b >>= 1;
        }
        return result;
    }

    private static boolean isPrime(long p) {
        if (p < 2) return false;
        if (p % 2 == 0) return p == 2;
        for (long i = 3; i * i <= p; i += 2) {
            if (p % i == 0) return false;
        }
        return true;
    }

    private static boolean checkFerma(long a, long x, long p) {
        if (a % p == 0) return true;
        return powerMod(a, p - 1, p) == 1;
    }

    private static long calculateFerma(long a, long x, long p) {
        if (a % p == 0) return 0;
        x = x % (p - 1);
        return powerMod(a, x, p);
    }

    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите числа для a^x mod p (p должно быть простым):");
        long a = sc.nextLong(), x = sc.nextLong(), p = sc.nextLong();

        if (!isPrime(p)) {
            System.out.println("Число p не простое. Запустите заново.");
            return;
        }
        if (!checkFerma(a, x, p)) {
            System.out.println("Теорема не выполняется. Запустите заново.");
            return;
        }
        long res = calculateFerma(a, x, p);
        System.out.println("Результат: " + res);
    }
}
