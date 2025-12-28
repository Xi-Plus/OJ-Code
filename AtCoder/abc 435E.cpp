// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int l, r;
	bool black;
	int sum;
	Node *left, *right;
};

void update(Node* cur, int l, int r) {
	// cout << "update " << cur->l << " " << cur->r << " for " << l << " " << r << endl;
	if (cur->black) {
		// cout << cur->l << " " << cur->r << " already black" << endl;
		return;
	}
	if (l <= cur->l && cur->r <= r) {
		// cout << "paint black " << cur->l << " " << cur->r << endl;
		cur->black = true;
		cur->sum = 0;
		return;
	}
	int mid = (cur->l + cur->r) / 2;
	if (!cur->left) {
		cur->left = new Node{cur->l, mid, false, mid - cur->l + 1, nullptr, nullptr};
		cur->right = new Node{mid + 1, cur->r, false, cur->r - mid, nullptr, nullptr};
	}
	if (l <= mid) {
		update(cur->left, l, r);
	}
	if (r > mid) {
		update(cur->right, l, r);
	}
	cur->sum = cur->left->sum + cur->right->sum;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int l, r;
	Node* root = new Node{1, n, false, n, nullptr, nullptr};
	while (q--) {
		cin >> l >> r;
		update(root, l, r);
		cout << root->sum << endl;
	}
}
