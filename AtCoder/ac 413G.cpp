// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct HashFunc {
	size_t operator()(const pair<int, int>& p) const {
		return (long long)p.first * 200000 + p.second;
	}
};
const int LEFT = 0, RIGHT = 1, TOP = 2, BOT = 3;
string name[] = {"LEFT", "RIGHT", "TOP", "BOT"};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, k;
	cin >> h >> w >> k;
	unordered_set<pair<int, int>, HashFunc> stone;
	for (int r = 0; r <= h + 1; r++) {
		stone.insert({r, 0});
		stone.insert({r, w + 1});
	}
	for (int c = 0; c <= w + 1; c++) {
		stone.insert({0, c});
		stone.insert({h + 1, c});
	}
	int x, y;
	while (k--) {
		cin >> x >> y;
		stone.insert({x, y});
	}
	int r = 1, c = 1, dir = LEFT, cnt = 0, nextDir;
	bool ans = true;
	while (true) {
		// cout << r << " " << c << " " << name[dir] << endl;
		if (dir == LEFT) {
			if (stone.find({r + 1, c}) == stone.end()) {
				if (stone.find({r + 1, c - 1}) == stone.end()) {
					r++;
					c--;
					dir = TOP;
				} else {
					r++;
				}
			} else {
				dir = BOT;
			}
		} else if (dir == BOT) {
			if (stone.find({r, c + 1}) == stone.end()) {
				if (stone.find({r + 1, c + 1}) == stone.end()) {
					r++;
					c++;
					dir = LEFT;
				} else {
					c++;
				}
			} else {
				dir = RIGHT;
			}
		} else if (dir == RIGHT) {
			if (stone.find({r - 1, c}) == stone.end()) {
				if (stone.find({r - 1, c + 1}) == stone.end()) {
					r--;
					c++;
					dir = BOT;
				} else {
					r--;
				}
			} else {
				dir = TOP;
			}
		} else {  // dir == TOP
			if (stone.find({r, c - 1}) == stone.end()) {
				if (stone.find({r - 1, c - 1}) == stone.end()) {
					r--;
					c--;
					dir = RIGHT;
				} else {
					c--;
				}
			} else {
				dir = LEFT;
			}
		}
		if (r == 1 && c == 1 && dir == TOP) {
			ans = false;
			break;
		}
		if (r == h && c == w) {
			break;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
