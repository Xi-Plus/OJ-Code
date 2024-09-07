// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int v[1000005];
int n;

void bubble_sort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

void selection_sort() {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[min]) {
				min = j;
			}
		}
		swap(v[i], v[min]);
	}
}

void insertion_sort() {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && v[j] < v[j - 1]) {
			swap(v[j], v[j - 1]);
			j--;
		}
	}
}

int tmp[1000005];
void merge_sort(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while (i <= mid || j <= r) {
		if (j > r || (i <= mid && v[i] < v[j])) {
			tmp[k++] = v[i++];
		} else {
			tmp[k++] = v[j++];
		}
	}
	for (int i = l; i <= r; i++) {
		v[i] = tmp[i];
	}
}

void built_in_sort() {
	sort(v, v + n);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// bubble_sort();
		// selection_sort();
		// insertion_sort();
		// merge_sort(0, n - 1);
		built_in_sort();

		cout << v[0];
		for (int i = 1; i < n; i++) {
			cout << " " << v[i];
		}
		cout << endl;
	}
}
/*
5
1 3 7 0 4
*/
