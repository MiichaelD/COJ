// https://www.hackerrank.com/challenges/abbr/problem
// November 5th, 2020.
// Michael Duarte

// Recursive string matching with backtracking + memoization.

#include <bits/stdc++.h>

using namespace std;

bool helper(const string &a, const string &b, vector<unordered_set<int>> &memo, size_t bInd = 0, size_t aInd = 0) {
    if (bInd == b.size()) {
        // Check there aren't any Uppercase letters remaining in 'a'
        for (;aInd < a.size(); ++aInd) {
            if (isupper(a.at(aInd))) {
                return false;
            }
        }
        return true;
    }
    if (memo[bInd].find(aInd) != memo[bInd].end()) {
        // We've been in this route before and it didn't work.
        return false;
    }
    for (; aInd < a.size(); ++aInd) {
        if (b.at(bInd) == toupper(a.at(aInd))) {
            if (helper(a, b, memo, bInd+1, aInd+1)) {
                return true;
            }
        }
        memo[bInd].insert(aInd); // memoization.
        if (isupper(a.at(aInd))) {
            // Uppercase letters can't be deleted/skipped.
            return false;
        }
        if ((a.size() - aInd) < (b.size() - bInd)) {
            return false;
        }
    }
    return false;
}

// Complete the abbreviation function below.
string abbreviation(const string &a, const string &b) {
    vector<unordered_set<int>> memo(b.size());
    return helper(a, b, memo) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
