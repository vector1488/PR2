import java.io.*;
import java.util.*;

public class Decrypt {
    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter encrypted file path: ");
        String path = sc.nextLine();

        try {
            byte[] data = java.nio.file.Files.readAllBytes(new File(path).toPath());

            System.out.println("Enter 3 shares (x y):");
            int[][] shares = new int[3][2];
            for (int i = 0; i < 3; i++) {
                shares[i][0] = sc.nextInt();
                shares[i][1] = sc.nextInt();
            }

            int key = SSSSen.shamirCombine(shares);

            // XOR-дешифрование
            byte[] decrypted = new byte[data.length];
            for (int i = 0; i < data.length; i++) {
                decrypted[i] = (byte)(data[i] ^ key);
            }

            File out = new File("decrypted.txt");
            try (FileOutputStream fos = new FileOutputStream(out)) {
                fos.write(decrypted);
            }
            System.out.println("File decrypted: " + out.getAbsolutePath());

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }
}
