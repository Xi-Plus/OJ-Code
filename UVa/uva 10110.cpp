#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool isp[65536];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	isp[0] = isp[1] = 1;
	for(int q=2; q<65536; q++) {
		for(int w=q*2; w<65536; w+=q) {
			isp[w] = 1;
		}
	}
	vector<int> p;
	for(int q=2; q<65536; q++) {
		if(!isp[q]) p.emplace_back(q);
	}
	long long n;
	while(cin>>n, n) {
		long long ans = 1;
		int k = 1, pidx = 0;
		for(int pidx=0; n>1 && pidx<p.size(); pidx++) {
			if(n%p[pidx] == 0) {
				while(n%p[pidx] == 0) {
					k++;
					n/=p[pidx];
				}
				ans *= k;
				k = 1;
			}
		}
		if(n > 1) ans *= 2;
		cout<<(ans&1?"yes":"no")<<endl;
	}
}
