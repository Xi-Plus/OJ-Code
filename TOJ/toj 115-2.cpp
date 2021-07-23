#include <bits/stdc++.h>
using namespace std;
int main() {
	map<int, string> arr;
	int n, k;
	string s;

	cin >> n;
	while (n--) {
		cin >> s >> k;
		arr[k] = s;
	}
	for (size_t i = 1; i <= 10; i++) {
		if(arr.count(i)) {
			cout << arr[i]<<endl;
		} else {
			cout<<"EMPTY"<<endl;
		}
		
	}
}
