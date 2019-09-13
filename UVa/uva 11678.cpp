#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, t, c1, c2;
	while(cin>>a>>b, a||b){
		set<int> v1, v2;
		for(int q=0; q<a; q++){
			cin>>t;
			v1.insert(t);
		}
		for(int q=0; q<b; q++){
			cin>>t;
			v2.insert(t);
		}
		c1=0;
		for(int t:v1){
			if(!v2.count(t)){
				c1++;
			}
		}
		c2=0;
		for(int t:v2){
			if(!v1.count(t)){
				c2++;
			}
		}
		cout<<min(c1, c2)<<endl;
	}
}
