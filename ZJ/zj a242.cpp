// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	long long a,x,b,cnt;
};
bool cmp(T v1,T v2){
	return v1.x<v2.x;
}
bool cmp2(T v1,long long n){
	return v1.cnt<n;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		T v[k];
		for(int q=0;q<k;q++){
			cin>>v[q].a>>v[q].b;
			v[q].x=v[q].b/v[q].a;
		}
		sort(v,v+k,cmp);
		v[0].cnt=v[0].a;
		for(int q=1;q<k;q++){
			v[q].cnt=v[q-1].cnt+v[q].a;
		}
		int it=lower_bound(v,v+k,(v[k-1].cnt+1)/2,cmp2)-v;
		int x=v[it].x;
		long long ans=0;
		for(int q=0;q<k;q++){
			ans+=abs(v[q].a*x-v[q].b);
		}
		cout<<ans<<endl;
	} 
}
