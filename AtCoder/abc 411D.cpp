// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int v[n + 1];
	memset(v, 0, sizeof(v));
	vector<string> trie;
	vector<int> trieParent;
	trie.push_back("");
	trieParent.push_back(0);

	int k, p;
	string s;
	while (q--) {
		cin >> k;
		if (k == 1) {
			cin >> p;
			v[p] = v[0];
		} else if (k == 2) {
			cin >> p >> s;
			int idx = trie.size();
			trie.push_back(s);
			trieParent.push_back(v[p]);
			v[p] = idx;
		} else if (k == 3) {
			cin >> p;
			v[0] = v[p];
		}
	}
	vector<string> ans;
	int cur = v[0];
	ans.push_back(trie[cur]);
	while (cur != 0) {
		cur = trieParent[cur];
		ans.push_back(trie[cur]);
	}
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i];
	}
	cout << endl;
}
