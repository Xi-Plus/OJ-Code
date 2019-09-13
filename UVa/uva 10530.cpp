#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s1, s2;
	int a=1, b=10;
	while(cin>>n, n){
		cin>>s1>>s2;
		if(s1[0]=='t'){
			if(s2[0]=='h'){
				b=min(b, n-1);
			}else{
				a=max(a, n+1);
			}
		}else{
			if(n>=a&&n<=b){
				cout<<"Stan may be honest"<<endl;
			}else{
				cout<<"Stan is dishonest"<<endl;
			}
			a=1;
			b=10;
		}
	}
}
