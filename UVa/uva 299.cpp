#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int bit[55];
int arr[55];
int l;
void add(int x, int v) {
	while (x <= l) {
		bit[x] += v;
		x += (x&(-x));
	}
}
int get(int x) {
	int ans = 0;
	while (x > 0) {
		ans += bit[x];
		x -= (x&(-x));
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--){
		cin>>l;
		memset(bit, 0, sizeof(bit));
		for(int q=0; q<l; q++){
			cin>>arr[q];
		}
		long long ans = 0;
		for (int i = 0; i < l; i++) {
			ans += get(l) - get(arr[i]);
			add(arr[i], 1);
		}
		cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
	}
}
