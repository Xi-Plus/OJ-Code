// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
string s;
int sum[500005];
struct Node {
	int l, r, lazy = 0, minv;
	Node *left, *right;
};

void build(Node* cur, int l, int r) {
	cur->l = l;
	cur->r = r;
	if (l == r) {
		cur->minv = sum[l];
	} else {
		int mid = (l + r) / 2;
		cur->left = new Node;
		cur->right = new Node;
		build(cur->left, l, mid);
		build(cur->right, mid + 1, r);
		cur->minv = min(cur->left->minv, cur->right->minv);
	}
}
void pushDown(Node* cur) {
	if (cur->lazy != 0 && cur->l != cur->r) {
		cur->left->lazy += cur->lazy;
		cur->left->minv += cur->lazy;
		cur->right->lazy += cur->lazy;
		cur->right->minv += cur->lazy;
		cur->lazy = 0;
	}
}
void update(Node* cur, int l, int r, int v) {
	if (r < cur->l || l > cur->r) {
		return;
	}
	if (l <= cur->l && cur->r <= r) {
		cur->lazy += v;
		cur->minv += v;
		return;
	}
	pushDown(cur);
	update(cur->left, l, r, v);
	update(cur->right, l, r, v);
	cur->minv = min(cur->left->minv, cur->right->minv);
}
int rangeMin(Node* cur, int l, int r) {
	if (r < cur->l || l > cur->r) {
		return 2e9;
	}
	if (l <= cur->l && cur->r <= r) {
		return cur->minv;
	}
	pushDown(cur);
	int ans = min(rangeMin(cur->left, l, r), rangeMin(cur->right, l, r));
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			sum[i + 1] = sum[i] + 1;
		} else {
			sum[i + 1] = sum[i] - 1;
		}
	}
	Node* root = new Node;
	build(root, 0, n);
	int q;
	cin >> q;
	int ty, l, r;
	char c;
	while (q--) {
		cin >> ty;
		if (ty == 1) {
			cin >> l >> c;
			if (c == 'A') {
				if (s[l - 1] != c) {
					s[l - 1] = c;
					update(root, l, n, 2);
				}
			} else {
				if (s[l - 1] != c) {
					s[l - 1] = c;
					update(root, l, n, -2);
				}
			}
		} else {
			cin >> l >> r;
			int a = rangeMin(root, l - 1, r);
			int b = rangeMin(root, l - 1, l - 1);
			if (a < b) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		}
	}
}
