#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int types = 3;
    string result = "";
    
    int hms[] = {0,0,0};
    
    //ascii for '0' == 48
    if(s[8] == 'P'){
        hms[0] += 12;
    }
    hms[0] += ((int)s[0] - 48)*10;
    hms[0] += (int)s[1] - 48;
    
    if(hms[0]%12 == 0){
        hms[0] -= 12;
    }
    
    hms[1] += ((int)s[3] - 48)*10;
    hms[1] += (int)s[4] - 48;
    
    hms[2] += ((int)s[6] - 48)*10;
    hms[2] += (int)s[7] - 48;
    
    for(int i = 0; i < 3; i++){
        if(hms[i] < 10){
            result += "0";
        }
        result += to_string(hms[i]);
        if(i != 2){
            result += ":";
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
