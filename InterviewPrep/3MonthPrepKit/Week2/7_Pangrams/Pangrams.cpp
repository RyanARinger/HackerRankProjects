#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    int len = s.size();
    int sum = 0;
    int A = 65; //ascii
    int alSize = 26;
    vector<int> al(alSize, 0);

    for(int i = 0; i < len; i++){
        if (al[toupper(s[i])%A] == 0){
            al[toupper(s[i])%A]++;
        }
    }
    
    for(int i = 0; i < 26; i++){
        sum += al[i];
    }
    
    if(sum == alSize){
        return "pangram";
    }
    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
