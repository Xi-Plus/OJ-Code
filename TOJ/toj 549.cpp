#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long mypow(long long a, long long b){
	if(b<0)return 0;
	long long ans=1;
	while(b--){
		ans*=a;
	}
	return ans;
}
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long m, e, n, sum=0, cnt=0;
	vector<int> plist;
	bool isp[10000]={};
	for(int q=2; q<10000; q++){
		if(!isp[q]){
			plist.push_back(q);
			for(int w=q*2; w<10000; w+=q){
				isp[w]=1;
			}
		}
	}
	cin>>m;
	for(int q=0; q<m; q++){
		cin>>e;
		bool check=(e!=0&&e!=1);
		for(auto p:plist){
			if(e%p==0){
				check=0;
				break;
			}
		}
		cnt+=check;
		if(check){
			sum+=e;
			sum=min(sum, 100000001LL);
		}
	}
	cin>>n;
	sum+=n;
	sum=max(sum, 1000LL);
	sum=min(sum, 100000001LL);
	if(m==1){
		cout<<(cnt?"Yes":"No");
	}else {
		cout<<cnt;
	}
//	cout<<" "<<(long long)pow(10, 7-(int)log10(sum-1))<<endl;
	cout<<" "<<mypow(10, 7-(int)log10(sum-1))<<endl;
}

