#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string a, b;
	int n;
	getline(cin, a);
	cin>>n;
	cin.ignore();
	for(int q=0; q<n; q++){
		getline(cin, b);
		if(a==b){
			cout<<q+1<<" ";
		}
	}
	cout<<endl;
}
