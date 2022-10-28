#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
    vector<vector<string>> res;
    res.push_back(grid);
    res.push_back(grid);
    vector<string> grid2 = grid;
    int r = grid.size();
    int c = grid[0].size();
    for(int t=2; t<=n; t++) {
        if(t%4 == 2) {
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == '.') {
                        grid[q][w] = 'X';
                    }
                }
            }
        } else if(t%4 == 3) {
            grid2 = grid;
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == 'O') {
                        if(q-1 >= 0) grid2[q-1][w] = 'O';
                        if(q+1 < r) grid2[q+1][w] = 'O';
                        if(w-1 >= 0) grid2[q][w-1] = 'O';
                        if(w+1 < c) grid2[q][w+1] = 'O';
                    }
                }
            }
            grid = grid2;
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == 'O') {
                        grid[q][w] = '.';
                    }
                }
            }
        } else if(t%4 == 0) {
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == '.') {
                        grid[q][w] = 'O';
                    }
                }
            }
        } else { // 1
            grid2 = grid;
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == 'X') {
                        if(q-1 >= 0) grid2[q-1][w] = 'X';
                        if(q+1 < r) grid2[q+1][w] = 'X';
                        if(w-1 >= 0) grid2[q][w-1] = 'X';
                        if(w+1 < c) grid2[q][w+1] = 'X';
                    }
                }
            }
            grid = grid2;
            for(int q=0; q<r; q++) {
                for(int w=0; w<c; w++) {
                    if(grid[q][w] == 'X') {
                        grid[q][w] = '.';
                    }
                }
            }
        }
        cout<<t<<endl;
        for(auto s: grid) {
            cout<<s<<endl;
        }
        res.push_back(grid);
        if(t > r*4+8) {
            break;
        }
    }
    cout<<"sz "<<res.size()<<endl;
    if (n > res.size()-1) {
        cout<<"n1 "<<n%4 + 8<<endl;
        grid = res[n%4 + 8];
    } else {
        cout<<"n2 "<<n<<endl;
        grid = res[n];
    }
    for(int q=0; q<r; q++) {
        for(int w=0; w<c; w++) {
            if(grid[q][w] == 'X') {
                grid[q][w] = 'O';
            }
        }
    }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
