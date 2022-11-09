#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {

    //READ THIS//
    /*
        This is a C++ implementation of the camelCase 4 problem.
        It works, but hackerrank will not accept pure C++ implementaions.
        <See the .java file>
    */

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // a == 97; z == 122
    // A == 65; Z == 90
    // lower - upper = 32
    string s;
    string output;
    int caseLimiter;
    int startInd;
    int endInd;

    while (getline(cin, s)) {

        output = "";

        caseLimiter = 0; //used to modify output cases

        startInd = 4;
        endInd = s.length();

        if (s[0] == 'S') { //Split S

            if (s[2] == 'M') { //Method M
                endInd -= 2; //forget the parenthesis
            }
            else if (s[2] == 'C') { //Class C

                if ((int)s[startInd] <= 90) { //if the first letter is uppercase
                    output += (int)s[startInd] + 32; //lowercase it
                }
                startInd++;//forget about the first letter
            }

            for (int i = startInd; i < endInd; i++) {
                if ((int)s[i] <= 90) { //capitalized
                    output += " "; //add a space
                    caseLimiter = 32; // lowercase it
                }
                output += (int)s[i] + caseLimiter;
                caseLimiter = 0;
            }
        }
        else {//Combine C
            if (s[2] == 'C') {
                if ((int)s[startInd] >= 97) { //if the first letter is lowercase
                    output += (int)s[startInd] - 32; //capitilize it
                }
                startInd++;//forget about the first letter
            }

            for (int i = startInd; i < endInd; i++) {
                if (s[i] == ' ') {
                    i++;
                    caseLimiter = -32;
                }
                output += (int)s[i] + caseLimiter;
                caseLimiter = 0;
            }

            if (s[2] == 'M') {
                output += "()";
            }
        }

        cout << output << endl;
    }
    return 0;
}
