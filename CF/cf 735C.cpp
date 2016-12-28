// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long v[100]={0,1};
	for(int q=2;;q++){
		v[q]=v[q-1]+v[q-2];
		if(v[q]>1e18)break;
	}
	long long n;
	cin>>n;
	cout<<upper_bound(v,v+88,n)-v-3<<endl;
}

