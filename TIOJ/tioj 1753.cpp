// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;cin>>n;
	int a,b;
	for(int q=0;q<n;q++){
		cin>>a>>b;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	v.push_back(-2147483647);
	long long lastnum=2147483647,lastcnt=0;
	long long same=0;
	for(int q=0;q<n+1;q++){
		if(lastnum!=v[q]){
			same+=lastcnt*(lastcnt-1)/2;
			lastcnt=1;
			lastnum=v[q];
		}else {
			lastcnt++;
		}
	}
	cout<<n*(n-1)/2-same<<endl;
}
