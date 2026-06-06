// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int h, w;
bool valid(int r, int c) {
	return 1 <= r && r <= h && 1 <= c && c <= w;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	char s[h + 2][w + 2];
	vector<pair<int, int>> a, b;
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cin >> s[r][c];
			if (s[r][c] == '#') {
				a.push_back({r, c});
			}
		}
	}
	int nr, nc;
	for (auto& p : a) {
		for (int i = 0; i < 8; i++) {
			nr = p.first + dr[i];
			nc = p.second + dc[i];
			if (valid(nr, nc) && s[nr][nc] == '.') {
				s[nr][nc] = '-';
				b.push_back({nr, nc});
			}
		}
	}
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			if (s[r][c] == '#') {
				s[r][c] = '.';
			}
		}
	}

	while (true) {
		a.clear();
		for (auto& p : b) {
			for (int i = 0; i < 8; i++) {
				nr = p.first + dr[i];
				nc = p.second + dc[i];
				if (valid(nr, nc) && s[nr][nc] == '.') {
					s[nr][nc] = '#';
					a.push_back({nr, nc});
				}
			}
		}
		if (a.empty()) {
			break;
		}
		b.clear();
		for (auto& p : a) {
			for (int i = 0; i < 8; i++) {
				nr = p.first + dr[i];
				nc = p.second + dc[i];
				if (valid(nr, nc) && s[nr][nc] == '.') {
					s[nr][nc] = '-';
					b.push_back({nr, nc});
				}
			}
		}
	}
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			if (s[r][c] == '#') {
				cout << '#';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
}
