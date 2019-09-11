#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v;
	for(int q=0; q<=317; q++){
		v.push_back(q*q);
	}
	int a, b;
	while(cin>>a>>b, a||b){
		cout<<upper_bound(v.begin(), v.end(), b)-lower_bound(v.begin(), v.end(), a)<<endl;
	}
}
