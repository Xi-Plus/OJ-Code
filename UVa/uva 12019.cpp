#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string dayname[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int mday [] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int t, m, d;
	cin>>t;
	while(t--){
		cin>>m>>d;
		int sum=d-1-1+7; // 2011/1/1 is Sunday
		for(int q=1; q<m; q++){
			sum+=mday[q];
		}
		cout<<dayname[sum%7]<<endl;
	}
}
