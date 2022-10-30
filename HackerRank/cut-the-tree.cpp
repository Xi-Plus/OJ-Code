#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int n;
vector<vector<int>> E;
bool used[100005];
int nodev[100005];
int nodesum[100005];
int allsum;
int ans;

int dfssum(int cur) {
	used[cur] = true;
	int sum = 0;
	for (auto &next : E[cur]) {
		if (!used[next]) {
			sum += dfssum(next);
		}
	}
	nodesum[cur] = sum + nodev[cur];
	return nodesum[cur];
}

void dfsans(int cur) {
	used[cur] = true;
	for (auto &next : E[cur]) {
		if (!used[next]) {
			ans = min(ans, abs((allsum - nodesum[next]) - nodesum[next]));
			dfsans(next);
		}
	}
}

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
	n = data.size();
	memset(used, 0, n + 5);
	memset(nodev, 0, n + 5);
	memset(nodesum, 0, n + 5);
	allsum = 0;
	for (int q = 0; q < data.size(); q++) {
		nodev[q + 1] = data[q];
		allsum += data[q];
	}
	E.clear();
	E.resize(n + 1);
	for (auto &e : edges) {
		E[e[0]].push_back(e[1]);
		E[e[1]].push_back(e[0]);
	}

	dfssum(1);

	ans = 1e9;
	memset(used, 0, n + 5);
	dfsans(1);

	return ans;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string data_temp_temp;
	getline(cin, data_temp_temp);

	vector<string> data_temp = split(rtrim(data_temp_temp));

	vector<int> data(n);

	for (int i = 0; i < n; i++) {
		int data_item = stoi(data_temp[i]);

		data[i] = data_item;
	}

	vector<vector<int>> edges(n - 1);

	for (int i = 0; i < n - 1; i++) {
		edges[i].resize(2);

		string edges_row_temp_temp;
		getline(cin, edges_row_temp_temp);

		vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			int edges_row_item = stoi(edges_row_temp[j]);

			edges[i][j] = edges_row_item;
		}
	}

	int result = cutTheTree(data, edges);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

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
