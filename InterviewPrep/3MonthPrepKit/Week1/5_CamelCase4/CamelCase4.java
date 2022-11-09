import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        String s;
        String output;
        int caseLimiter;
        int startInd;
        int endInd;

        while(scan.hasNextLine()) {
            // a == 97; z == 122
            // A == 65; Z == 90
            // lower - upper = 32

            //S - split
            //C - combine

            //M - method
            //C - class
            //V - variable
            s = scan.nextLine();

            output = "";

            caseLimiter = 0; //used to modify output cases

            startInd = 4;
            endInd = s.length();

            if (s.charAt(0) == 'S') { //Split S

                if (s.charAt(2) == 'M') { //Method M
                    endInd -= 2; //forget the parenthesis
                }
                else if (s.charAt(2) == 'C') { //Class C

                    if ((int)s.charAt(startInd) <= 90) { //if the first letter is uppercase
                        output += (char)((int)s.charAt(startInd) + 32); //lowercase it
                    }
                    startInd++;//forget about the first letter
                }

                for (int i = startInd; i < endInd; i++) {
                    if ((int)s.charAt(i) <= 90) { //capitalized
                        output += " "; //add a space
                        caseLimiter = 32; // lowercase it
                    }
                    output += (char)((int)s.charAt(i) + caseLimiter);
                    caseLimiter = 0;
                }
            }
            else {//Combine C
                if (s.charAt(2) == 'C') {
                    if ((int)s.charAt(startInd) >= 97) { //if the first letter is lowercase
                        output += (char)((int)s.charAt(startInd) - 32); //capitilize it
                    }
                    startInd++;//forget about the first letter
                }

                for (int i = startInd; i < endInd; i++) {
                    if (s.charAt(i) == ' ') {
                        i++;
                        caseLimiter = -32;
                    }
                    output += (char)((int)s.charAt(i) + caseLimiter);
                    caseLimiter = 0;
                }

                if (s.charAt(2) == 'M') {
                    output += "()";
                }
            }
            System.out.println(output);
        }
        
    }
}
