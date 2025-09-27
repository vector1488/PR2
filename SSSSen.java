import java.util.*;

public class SSSSen {
    private static final int PRIME = 257; // простое > 255

    private static int modPow(int base, int exp, int mod) {
        int res = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    public static List<int[]> shamirSplit(int secret, int n, int k) {
        Random rand = new Random();
        int[] coeffs = new int[k];
        coeffs[0] = secret;
        for (int i = 1; i < k; i++) {
            coeffs[i] = rand.nextInt(PRIME);
        }

        List<int[]> shares = new ArrayList<>();
        for (int x = 1; x <= n; x++) {
            int y = 0;
            int xp = 1;
            for (int c : coeffs) {
                y = (y + c * xp) % PRIME;
                xp = (xp * x) % PRIME;
            }
            shares.add(new int[]{x, y});
        }
        return shares;
    }

    public static int shamirCombine(int[][] shares) {
        int k = shares.length;
        int secret = 0;
        for (int i = 0; i < k; i++) {
            int xi = shares[i][0];
            int yi = shares[i][1];

            int num = 1;
            int den = 1;
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                int xj = shares[j][0];
                num = (num * (PRIME - xj)) % PRIME;
                den = (den * (xi - xj + PRIME)) % PRIME;
            }

            // обратный элемент через modPow
            int inv = modPow(den, PRIME - 2, PRIME);
            int li = (num * inv) % PRIME;
            secret = (secret + yi * li) % PRIME;
        }
        return secret;
    }
}
