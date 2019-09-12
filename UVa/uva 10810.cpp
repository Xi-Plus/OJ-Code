#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int bit[500005];
int arr[500005];
int arr2[500005];
int n;
void add(int x, int v) {
	while (x <= n) {
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
	while(cin>>n, n){
		memset(bit, 0, sizeof(bit));
		for(int q=0; q<n; q++){
			cin>>arr[q];
			arr2[q]=arr[q];
		}
		sort(arr2, arr2+n);
		for(int q=0; q<n; q++){
			arr[q]=lower_bound(arr2, arr2+n, arr[q])-arr2+1;
		}
		
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += get(n) - get(arr[i]);
			add(arr[i], 1);
		}
		cout<<ans<<endl;
	}
}
