// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int gcd(int a,int b){
	while((a%=b)&&(b%=a));
	return a+b;
}
struct num{
	int a,b;
	double c;
};
bool cmp(num a,num b){
	return a.c<b.c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<num>v;
	for(int q=2;q<=n;q++){
		for(int w=1;w<q;w++){
			if(gcd(w,q)==1){
				v.push_back({w,q,double(w)/q});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int sz=v.size();
	cout<<sz<<endl;
	if(sz<n){
		cout<<v[0].a<<"/"<<v[0].b<<endl;
	}else {
		cout<<v[n-1].a<<"/"<<v[n-1].b<<endl;
	}
}