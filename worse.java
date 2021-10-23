// 2021 UCF HSPT - Worse Code
// Author: Sathvik Kuthuru

import java.util.Scanner;

public class worse {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Scan in the number of words to process
        int numTests = scan.nextInt();
        // Consume the rest of the line
        scan.nextLine();
        for(int i = 0; i < numTests; i++) {
            // Scan in the entire line at once and split it by spaces
            String[] line = scan.nextLine().split(" ");
            // After splitting we get an array of strings with each being a letter
            for(String letter : line) {
                // Simple way to convert the string to the actual letter
                char currLetter = (char) ('A' + letter.length() - 1);
                // Print it out
                System.out.print(currLetter);
            }
            // Print a newline between test cases
            System.out.println();
        }
    }
}
