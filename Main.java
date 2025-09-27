import java.util.Scanner;

public class Main {
    private static void showUsage() {
        System.out.println("Practice 2. Main menu\n" +
                "1 - Run Exercise 1\n" +
                "2 - Run Exercise 2\n" +
                "3 - Run Exercise 3\n" +
                "4 - Run Exercise 4\n" +
                "5 - Run Exercise 5\n");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char choice;

        do {
            showUsage();
            choice = sc.next().charAt(0);
            switch (choice) {
                case '1' -> Ferma.run();
                case '2' -> Extevklid.run();
                case '3' -> Modules.run();
                case '4' -> Shamir.run();
                case '5' -> Fraction.run();
                case 'q', 'Q' -> System.out.println("Leaving the program...");
                default -> System.out.println("Wrong choice!");
            }
        } while (choice != 'q' && choice != 'Q');
    }
}

