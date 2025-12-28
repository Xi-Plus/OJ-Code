// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int l, r;
	int maxH;
	int maxHidx;
	Node *left, *right;
};
Node* root = new Node();

int p[200005];

long long ans = 0;

void build(Node* cur, int l, int r) {
	cur->l = l;
	cur->r = r;
	if (l == r) {
		cur->maxH = p[l];
		cur->maxHidx = l;
		return;
	}
	int mid = (l + r) / 2;
	cur->left = new Node();
	cur->right = new Node();
	build(cur->left, l, mid);
	build(cur->right, mid + 1, r);
	if (cur->left->maxH >= cur->right->maxH) {
		cur->maxH = cur->left->maxH;
		cur->maxHidx = cur->left->maxHidx;
	} else {
		cur->maxH = cur->right->maxH;
		cur->maxHidx = cur->right->maxHidx;
	}
}

int query(Node* cur, int l, int r) {
	if (cur->r < l || cur->l > r) {
		// cout << "query " << l << " " << r << " bad " << cur->l << " " << cur->r << endl;
		return -1;
	}
	if (l <= cur->l && cur->r <= r) {
		// cout << "query " << l << " " << r << " cache " << cur->maxHidx << endl;
		return cur->maxHidx;
	}
	int leftIdx = query(cur->left, l, r);
	int rightIdx = query(cur->right, l, r);
	if (leftIdx == -1) {
		// cout << "query " << l << " " << r << " " << rightIdx << endl;
		return rightIdx;
	}
	if (rightIdx == -1) {
		// cout << "query " << l << " " << r << " " << leftIdx << endl;
		return leftIdx;
	}
	if (p[leftIdx] >= p[rightIdx]) {
		// cout << "query " << l << " " << r << " " << leftIdx << endl;
		return leftIdx;
	} else {
		// cout << "query " << l << " " << r << " " << rightIdx << endl;
		return rightIdx;
	}
}

long long dfs(int l, int r, int pos) {
	// cout << "dfs " << l << " " << r << " " << pos << endl;
	if (l == r) {
		return 0;
	}
	if (pos == l) {
		int rPos = query(root, l + 1, r);
		long long ans = dfs(l + 1, r, rPos) + abs(pos - rPos);
		// cout << "dfs " << l << " " << r << " " << pos << " ans " << ans << endl;
		return ans;
	}
	if (pos == r) {
		int lPos = query(root, l, r - 1);
		long long ans = dfs(l, r - 1, lPos) + abs(pos - lPos);
		// cout << "dfs " << l << " " << r << " " << pos << " ans " << ans << endl;
		return ans;
	}
	int lPos = query(root, l, pos - 1);
	int rPos = query(root, pos + 1, r);
	long long lRes = dfs(l, pos - 1, lPos) + abs(pos - lPos);
	long long rRes = dfs(pos + 1, r, rPos) + abs(pos - rPos);
	long long ans = max(lRes, rRes);
	// cout << "dfs " << l << " " << r << " " << pos << " ans " << lRes << " " << rRes << endl;
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	build(root, 1, n);
	int curL = 1, curR = n, pos = root->maxHidx;
	cout << dfs(curL, curR, pos) + abs(pos - root->maxHidx) << endl;
}
