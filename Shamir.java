import java.util.Scanner;

public class Shamir {
    public static void run() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter mode (e - encrypt, d - decrypt): ");
        char mode = sc.next().charAt(0);
        if (mode == 'e') {
            Encrypt.run();
        } else if (mode == 'd') {
            Decrypt.run();
        } else {
            System.out.println("Unknown mode");
        }
    }
}
