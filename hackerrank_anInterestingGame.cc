/**  
 * URL:         https://www.hackerrank.com/challenges/an-interesting-game-1/problem?isFullScreen=true
*/

// #include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gamingArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string gamingArray(vector<int> arr) {
    size_t maxLength = arr.size();
    int turns;
    while (true) {
        ++turns;
        int max = 0;
        size_t maxIndex = 0;
        for (size_t i = 0; i < maxLength; ++i) {
            if (arr[i] > max) {
                max = arr[i];
                maxIndex = i;
            }
        }
        maxLength = maxIndex;
        if (maxLength == 0) {
            return turns % 2 == 0 ? "ANDY" : "BOB";
        }
    }
    return "BOB";
}

// Works for non-repeated values
string gamingArrayOptimized(vector<int> &arr) {
    int target = arr[0];
    int repetitions = 1;
    vector<pair<int, size_t>> newArray(arr.size());
    for (size_t i = 0 ; i < arr.size(); ++i) {
        newArray[i] = make_pair(arr[i], i);
    }
    sort(newArray.begin(), newArray.end(),
         [](const pair<int, size_t> &p1, const pair<int, size_t> &p2){
             return p1.first > p2.first;
         });

    size_t max = newArray.size();
    size_t skips = 0;
    for (size_t i = 0 ; i < newArray.size(); ++i) {
        const auto &p = newArray[i];
        if (p.second >= max) {
            ++skips;
            continue;
        }
        // cout << "Checking: " << p.first << " @ " << p.second << " < " << max << endl;
        max = p.second;
        if (p.first == target && (--repetitions == 0)) {
            return (i - skips) % 2 == 1 ? "ANDY" : "BOB";
        }
    }
    return "WTF";
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string g_temp;
    getline(cin, g_temp);
    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);
        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));
        string arr_temp_temp;
        getline(cin, arr_temp_temp);
        vector<string> arr_temp = split(rtrim(arr_temp_temp));
        vector<int> arr(arr_count);
        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }
        string result = gamingArrayOptimized(arr);
        fout << result << "\n";
    }
    fout.close();
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
