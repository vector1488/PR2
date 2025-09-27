import java.io.*;
import java.util.*;

public class Encrypt {
    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter file path to encrypt: ");
        String path = sc.nextLine();

        try {
            byte[] data = java.nio.file.Files.readAllBytes(new File(path).toPath());
            Random rand = new Random();
            int key = 1 + rand.nextInt(255); // [1..255]

            // XOR-шифрование
            byte[] encrypted = new byte[data.length];
            for (int i = 0; i < data.length; i++) {
                encrypted[i] = (byte)(data[i] ^ key);
            }

            File out = new File("encrypted.txt");
            try (FileOutputStream fos = new FileOutputStream(out)) {
                fos.write(encrypted);
            }
            System.out.println("File encrypted: " + out.getAbsolutePath());

            // Разделение ключа Шамира (5 частей, порог = 3)
            List<int[]> shares = SSSSen.shamirSplit(key, 5, 3);
            System.out.println("Key shares:");
            for (int[] s : shares) {
                System.out.println(s[0] + " " + s[1]);
            }

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }
}
