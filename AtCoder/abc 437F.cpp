// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node {
	int l, r;
	Node *left, *right;
	int ans[4] = {0, 0, 0, 0};
};
Node* root = new Node();
long long x[200005], y[200005];

int dis(int mode, int x, int y) {
	if (mode == 0) {
		return x + y;
	} else if (mode == 1) {
		return y - x;
	} else if (mode == 2) {
		return -x - y;
	} else {
		return x - y;
	}
}

void build(Node* cur, int l, int r) {
	cur->l = l;
	cur->r = r;
	if (l == r) {
		for (int i = 0; i < 4; i++) {
			cur->ans[i] = l;
		}
		return;
	}
	int m = (l + r) / 2;
	cur->left = new Node();
	cur->right = new Node();
	build(cur->left, l, m);
	build(cur->right, m + 1, r);
	for (int i = 0; i < 4; i++) {
		if (dis(i, x[cur->left->ans[i]], y[cur->left->ans[i]]) > dis(i, x[cur->right->ans[i]], y[cur->right->ans[i]])) {
			cur->ans[i] = cur->left->ans[i];
		} else {
			cur->ans[i] = cur->right->ans[i];
		}
	}
}
void update(Node* cur, int i) {
	if (cur->l == cur->r) {
		return;
	}
	if (i <= cur->left->r) {
		update(cur->left, i);
	} else {
		update(cur->right, i);
	}
	for (int i = 0; i < 4; i++) {
		if (dis(i, x[cur->left->ans[i]], y[cur->left->ans[i]]) > dis(i, x[cur->right->ans[i]], y[cur->right->ans[i]])) {
			cur->ans[i] = cur->left->ans[i];
		} else {
			cur->ans[i] = cur->right->ans[i];
		}
	}
}
long long query(Node* cur, int l, int r, int qx, int qy) {
	if (cur->r < l || cur->l > r) {
		return -1;
	}
	if (l <= cur->l && cur->r <= r) {
		long long ans = 0;
		for (int i = 0; i < 4; i++) {
			ans = max(ans, abs(qx - x[cur->ans[i]]) + abs(qy - y[cur->ans[i]]));
		}
		return ans;
	}
	return max(query(cur->left, l, r, qx, qy), query(cur->right, l, r, qx, qy));
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	build(root, 1, n);
	int t, i, l, r;
	long long qx, qy;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> i >> qx >> qy;
			x[i] = qx;
			y[i] = qy;
			update(root, i);
		} else {
			cin >> l >> r >> qx >> qy;
			cout << query(root, l, r, qx, qy) << endl;
		}
	}
}
