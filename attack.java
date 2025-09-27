import java.util.*;

public class attack {
    private static final int PRIME = 257;

    static int modPow(int a, int b, int c) {
        long result = 1;
        a %= c;
        while (b > 0) {
            if ((b & 1) == 1) result = (result * a) % c;
            a = (a * a) % c;
            b >>= 1;
        }
        return (int) result;
    }

    static int shamirCombine(List<int[]> shares) {
        long secret = 0;
        for (int i = 0; i < shares.size(); i++) {
            long xi = shares.get(i)[0];
            long yi = shares.get(i)[1];

            long num = 1, den = 1;
            for (int j = 0; j < shares.size(); j++) {
                if (i == j) continue;
                long xj = shares.get(j)[0];
                num = (num * (PRIME - xj)) % PRIME;
                den = (den * (xi - xj + PRIME)) % PRIME;
            }
            long inv = modPow((int) den, PRIME - 2, PRIME);
            long term = yi * num % PRIME * inv % PRIME;
            secret = (secret + term) % PRIME;
        }
        return (int) secret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<int[]> shares = new ArrayList<>();
        System.out.println("Атака на Shamir (5,3). Введите 3 доли (x y):");
        for (int i = 0; i < 3; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            shares.add(new int[]{x,y});
        }
        int key = shamirCombine(shares);
        System.out.println("Восстановленный ключ: " + key);
    }
}

