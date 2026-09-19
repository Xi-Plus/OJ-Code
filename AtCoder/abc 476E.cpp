// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int p[200005];
struct Node {
	int l, r;
	int min, max;
	Node *left = nullptr, *right = nullptr;
};

void pull(Node* root) {
	if (p[root->left->min] < p[root->right->min]) {
		root->min = root->left->min;
	} else {
		root->min = root->right->min;
	}
	if (p[root->left->max] > p[root->right->max]) {
		root->max = root->left->max;
	} else {
		root->max = root->right->max;
	}
}

void build(Node* root, int l, int r) {
	root->l = l;
	root->r = r;
	if (l == r) {
		root->min = l;
		root->max = l;
		return;
	}
	root->left = new Node;
	root->right = new Node;
	int m = (l + r) / 2;
	build(root->left, l, m);
	build(root->right, m + 1, r);
	pull(root);
}

void update(Node* root, int q) {
	if (root->l == root->r) {
		return;
	}
	if (q <= root->left->r) {
		update(root->left, q);
	} else {
		update(root->right, q);
	}
	pull(root);
}

int qMin(Node* root, int l, int r) {
	if (r < root->l || l > root->r) {
		return -1;
	}
	if (l <= root->l && root->r <= r) {
		return root->min;
	}
	int a = qMin(root->left, l, r);
	int b = qMin(root->right, l, r);
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	if (p[a] < p[b]) {
		return a;
	} else {
		return b;
	}
}

int qMax(Node* root, int l, int r) {
	if (r < root->l || l > root->r) {
		return -1;
	}
	if (l <= root->l && root->r <= r) {
		return root->max;
	}
	int a = qMax(root->left, l, r);
	int b = qMax(root->right, l, r);
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	if (p[a] > p[b]) {
		return a;
	} else {
		return b;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	Node* root = new Node;
	build(root, 1, n);
	int l, r, minIdx, maxIdx;
	while (m--) {
		cin >> l >> r;
		minIdx = qMin(root, l, r);
		maxIdx = qMax(root, l, r);
		swap(p[minIdx], p[maxIdx]);
		update(root, minIdx);
		update(root, maxIdx);
	}
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
