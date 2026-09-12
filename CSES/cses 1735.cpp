// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long v[200005];
struct Node {
	int l, r;
	long long lazy_add = 0;
	long long lazy_set = 0;
	long long sum = 0;
	Node *left, *right;
};

void build(Node* cur, int l, int r) {
	cur->l = l;
	cur->r = r;
	if (l == r) {
		cur->sum = v[l];
	} else {
		int mid = (l + r) / 2;
		cur->left = new Node;
		cur->right = new Node;
		build(cur->left, l, mid);
		build(cur->right, mid + 1, r);
		cur->sum = cur->left->sum + cur->right->sum;
	}
}

void pushDown(Node* cur) {
	if (cur->l != cur->r) {
		long long len_left = cur->left->r - cur->left->l + 1;
		long long len_right = cur->right->r - cur->right->l + 1;

		if (cur->lazy_set != 0) {
			cur->left->lazy_set = cur->lazy_set;
			cur->left->lazy_add = 0;
			cur->left->sum = cur->lazy_set * len_left;
			cur->right->lazy_set = cur->lazy_set;
			cur->right->lazy_add = 0;
			cur->right->sum = cur->lazy_set * len_right;
			cur->lazy_set = 0;
		}

		if (cur->lazy_add != 0) {
			if (cur->left->lazy_set != 0) {
				cur->left->lazy_set += cur->lazy_add;
			} else {
				cur->left->lazy_add += cur->lazy_add;
			}
			cur->left->sum += cur->lazy_add * len_left;
			if (cur->right->lazy_set != 0) {
				cur->right->lazy_set += cur->lazy_add;
			} else {
				cur->right->lazy_add += cur->lazy_add;
			}
			cur->right->sum += cur->lazy_add * len_right;
			cur->lazy_add = 0;
		}
	}
}
void add(Node* cur, int l, int r, long long v) {
	if (r < cur->l || l > cur->r) {
		return;
	}
	if (l <= cur->l && cur->r <= r) {
		if (cur->lazy_set != 0) {
			cur->lazy_set += v;
		} else {
			cur->lazy_add += v;
		}
		cur->sum += v * (cur->r - cur->l + 1);
		return;
	}
	pushDown(cur);
	add(cur->left, l, r, v);
	add(cur->right, l, r, v);
	cur->sum = cur->left->sum + cur->right->sum;
}
void replace(Node* cur, int l, int r, long long v) {
	if (r < cur->l || l > cur->r) {
		return;
	}
	if (l <= cur->l && cur->r <= r) {
		cur->lazy_set = v;
		cur->lazy_add = 0;
		cur->sum = v * (cur->r - cur->l + 1);
		return;
	}
	pushDown(cur);
	replace(cur->left, l, r, v);
	replace(cur->right, l, r, v);
	cur->sum = cur->left->sum + cur->right->sum;
}
long long rangeSum(Node* cur, int l, int r) {
	if (r < cur->l || l > cur->r) {
		return 0;
	}
	if (l <= cur->l && cur->r <= r) {
		return cur->sum;
	}
	pushDown(cur);
	long long ans = rangeSum(cur->left, l, r) + rangeSum(cur->right, l, r);
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	Node* root = new Node;
	build(root, 1, n);
	int type, l, r;
	long long x;
	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> l >> r >> x;
			add(root, l, r, x);
		} else if (type == 2) {
			cin >> l >> r >> x;
			replace(root, l, r, x);
		} else if (type == 3) {
			cin >> l >> r;
			cout << rangeSum(root, l, r) << endl;
		}
	}
}
