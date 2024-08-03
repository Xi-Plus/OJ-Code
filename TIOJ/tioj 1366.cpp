// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	string s;
	int sum;
	int index;
};
bool cmp(T a,T b){
	if(a.sum==b.sum) return a.index<b.index;
	return a.sum<b.sum;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string s;
	cin>>n;
	vector<T> v;
	for(int q=0;q<n;q++){
		cin>>s;
		int sum=0;
		int sz=s.size();
		for(int w=0;w<sz;w++){
			sum+=s[w]-'0';
		}
		v.push_back({s,sum,q});
	}
	sort(v.begin(),v.end(),cmp);
	int sz=v.size();
	cout<<v[0].s;
	for(int q=1;q<sz;q++){
		cout<<" "<<v[q].s;
	}
	cout<<endl;
}
