// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string input[] = {
	".##..#.#",
	"#.#.....",
	".#...#.#",
	"#...#...",
	"........",
	"#.#.#.#.",
	".#.....#",
	"........",
	".#...#.#",
	"..#.....",
	"...#....",
	"#.....#.",
};
int v[14][10];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
const int MAXN = 100;
bool isP[MAXN];
int bestVal = 0;
bool check_connectivity(int r, int c, int val) {
	int remaining_steps = 96 - val + 1;
	if (remaining_steps == 0) return true;

	bool visited[14][10] = {false};
	queue<pair<int, int>> q;
	q.push({r, c});
	visited[r][c] = true;
	int count = 0;
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		count++;
		for (int i = 0; i < 4; i++) {
			int nr = curr.first + dr[i];
			int nc = curr.second + dc[i];
			if (v[nr][nc] == 0 && !visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({nr, nc});
			}
		}
	}
	return count == remaining_steps;
}
void dfs(int r, int c, int val) {
	if (v[r][c] != 0) {
		return;
	}
	if (isP[val] ^ (input[r - 1][c - 1] == '#')) {
		return;
	}
	if (val % 3 == 0 && !check_connectivity(r, c, val)) {
		return;
	}
	v[r][c] = val;
	if (r == 12 && c == 6 && val == 96) {
		cout << "found:" << endl;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 8; j++) {
				cout << setw(2) << v[i][j] << " ";
			}
			cout << endl;
		}
		v[r][c] = 0;
		return;
	}
	// if (val >= bestVal) {
	// 	cout << "check: " << val << endl;
	// 	for (int i = 1; i <= 12; i++) {
	// 		for (int j = 1; j <= 8; j++) {
	// 			cout << setw(2) << v[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	bestVal = val;
	// }
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		dfs(nr, nc, val + 1);
	}
	v[r][c] = 0;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	clock_t begin = clock();
	fill_n(isP, MAXN, true);
	isP[1] = false;
	for (int i = 2; i < MAXN; i++) {
		if (isP[i]) {
			for (int j = i * 2; j < MAXN; j += i) {
				isP[j] = false;
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (isP[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	for (int i = 0; i <= 9; i++) {
		v[0][i] = -1;
		v[13][i] = -1;
	}
	for (int i = 0; i <= 13; i++) {
		v[i][0] = -1;
		v[i][9] = -1;
	}
	dfs(1, 4, 1);
	clock_t end = clock();
	cout << double(end - begin) / CLOCKS_PER_SEC << endl;
}
