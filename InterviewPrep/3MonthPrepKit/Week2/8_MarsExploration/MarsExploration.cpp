#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int changes = 0;
    int index = 0;
    int len = s.size();
    
    while(index < len){
        if(s[index] != 'S'){
            changes++;
        }
        if(s[index+1] != 'O'){
            changes++;
        }
        if(s[index+2] != 'S'){
            changes++;
        }
        
        index += 3;
    }
    return changes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
