// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) : val(v), next(nullptr) {}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q, t, x, y;
	cin >> q;
	Node* head = new Node(0);
	unordered_map<int, Node*> node_map;
	node_map[0] = head;
	for (int i = 1; i <= q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			Node* newNode = new Node(i);
			node_map[i] = newNode;
			newNode->next = node_map[x]->next;
			node_map[x]->next = newNode;
		} else {
			cin >> x >> y;
			Node* curX = node_map[x]->next;
			Node* curY = node_map[y]->next;
			long long ansX = 0, ansY = 0;
			while (curX && curY) {
				if (curX->val == y) {
					cout << ansX << endl;
					node_map[x]->next = node_map[y];
					curX = nullptr;
					curY = nullptr;
					break;
				}
				ansX += curX->val;
				curX = curX->next;
				if (curY->val == x) {
					cout << ansY << endl;
					node_map[y]->next = node_map[x];
					curX = nullptr;
					curY = nullptr;
					break;
				}
				ansY += curY->val;
				curY = curY->next;
			}
			while (curX) {
				if (curX->val == y) {
					cout << ansX << endl;
					node_map[x]->next = node_map[y];
					break;
				}
				ansX += curX->val;
				curX = curX->next;
			}
			while (curY) {
				if (curY->val == x) {
					cout << ansY << endl;
					node_map[y]->next = node_map[x];
					break;
				}
				ansY += curY->val;
				curY = curY->next;
			}
		}
	}
}
