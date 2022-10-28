#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    unordered_map<char, int> cnt;
    for(char c : s) {
        if ('a' <= c && c <= 'z') {
            cnt[c] = 1;
        } else if ('A' <= c && c <= 'Z') {
            cnt[c-'A'+'a'] = 1;
        }
    }
    for(char c='a'; c <= 'z'; c++) {
        if (cnt[c] == 0) {
            return "not pangram";
        }
    }
    return "pangram";
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
