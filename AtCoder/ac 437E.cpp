// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	vector<int> idx;
	map<int, Node*> next;
};
Node* root = new Node();
void dfs(Node* cur) {
	for (auto idx : cur->idx) {
		cout << idx << ' ';
	}
	for (auto& [num, next] : cur->next) {
		dfs(next);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<Node*> nodes(n + 1);
	nodes[0] = root;
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (nodes[x]->next.find(y) == nodes[x]->next.end()) {
			nodes[x]->next[y] = new Node();
		}
		nodes[x]->next[y]->idx.push_back(i);
		nodes[i] = nodes[x]->next[y];
	}
	dfs(root);
	cout << endl;
}
