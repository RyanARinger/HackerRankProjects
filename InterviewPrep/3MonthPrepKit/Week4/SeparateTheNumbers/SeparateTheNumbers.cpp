#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    string answer, beauty;
    int size = s.length();
    long startingNum, runningDigit;
    
    
    answer = "NO";
    for(int i = 1; i < (size/2) + 1; i++){
        beauty = s.substr(0, i);
        startingNum = runningDigit = stol(beauty);
        
        while(beauty.length() < size){
            beauty += to_string(++runningDigit);
        }        
        
        if(beauty == s){
            answer = "YES " + to_string(startingNum);
        }
    }
    
    cout << answer << endl;
    
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
