#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int pp[10000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int q=1; q<10000005; q++) {
		pp[q] = q;
	}
	for(int q=2; q<3165; q++) {
		if(pp[q] == q) {
			for(int w=q*2; w<10000005; w+=q) {
				while(pp[w]%q==0 && pp[w] != q) pp[w] /= q;
			}
		} 
	}
	int n, a, ans2;
	cin>>n;
	while(n--) {
		cin>>a;
		ans2 = pp[a];
		while(a%ans2==0) a/=ans2;
		cout<<pp[a]<<" "<<ans2<<endl;
	}
}
