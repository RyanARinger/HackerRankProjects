#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    
    int size = arr.size();
    long min, max, sum;
    min = max = sum = arr[0];
    
    
    //cout << "ARR[0] = " << arr[0] << endl;
    //cout << "MIN = " << min << endl;
    //cout << "MAX = " << max << endl;
    
    for(int i = 1; i < size; i++){
        //cout << endl << endl;
        //cout << "ARR[" << i << "] = " << arr[i] << endl;
        
        if(arr[i] > max) max = arr[i];
        else if(arr[i] < min) min = arr[i];
        
        sum += arr[i];
        
        //cout << "ARR[" << i << "] = " << arr[i] << endl;
        //cout << "MIN = " << min << endl;
        //cout << "MAX = " << max << endl;
        
    }
    
    
    cout << sum - max << " " << sum - min;
    
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
