// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
struct Query {
	int a, b, c, d;
	int ans = 0;
};
struct Q2 {
	int l, r, top, idx, f;
	bool operator<(const Q2& other) const {
		return top < other.top;
	}
};
Query qq[200005];
int l[200005], r[200005];

struct Node {
	int l, r, sum = 0, lazy = 0;
	Node *left, *right;
};
Node* root = new Node;
void build(Node* root, int l, int r) {
	root->l = l;
	root->r = r;
	if (l == r) {
		return;
	}
	root->left = new Node;
	root->right = new Node;
	int m = (l + r) / 2;
	build(root->left, l, m);
	build(root->right, m + 1, r);
}
void push(Node* root) {
	if (root->lazy) {
		root->left->lazy += root->lazy;
		root->left->sum += (root->left->r - root->left->l + 1) * root->lazy;
		root->right->lazy += root->lazy;
		root->right->sum += (root->right->r - root->right->l + 1) * root->lazy;
		root->lazy = 0;
	}
}
void pull(Node* root) {
	root->sum = root->left->sum + root->right->sum;
}
void update(Node* root, int l, int r) {
	if (r < root->l || l > root->r) {
		return;
	}
	if (l <= root->l && root->r <= r) {
		root->lazy += 1;
		root->sum += root->r - root->l + 1;
		return;
	}
	push(root);
	update(root->left, l, r);
	update(root->right, l, r);
	pull(root);
}
int query(Node* root, int l, int r) {
	if (r < root->l || l > root->r) {
		return 0;
	}
	if (l <= root->l && root->r <= r) {
		return root->sum;
	}
	push(root);
	return query(root->left, l, r) + query(root->right, l, r);
}

signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	vector<Q2> q2;
	for (int i = 1; i <= q; i++) {
		cin >> qq[i].a >> qq[i].b >> qq[i].c >> qq[i].d;
		if (qq[i].a > 1) {
			q2.push_back({qq[i].c, qq[i].d, qq[i].a - 1, i, -1});
		}
		q2.push_back({qq[i].c, qq[i].d, qq[i].b, i, 1});
	}
	sort(q2.begin(), q2.end());
	build(root, 1, m);
	int q2i = 0;
	for (int i = 1; i <= n; i++) {
		update(root, l[i], r[i]);
		while (q2i < q2.size() && q2[q2i].top <= i) {
			int ans = query(root, q2[q2i].l, q2[q2i].r);
			qq[q2[q2i].idx].ans += ans * q2[q2i].f;
			q2i++;
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << qq[i].ans << endl;
	}
}
