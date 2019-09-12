#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int calc(int x, int y){
	return (x+y+1)*(x+y+2)/2-y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, a, b, c, d;
	cin>>T;
	for(int t=1; t<=T; t++){
		cin>>a>>b>>c>>d;
		cout<<"Case "<<t<<": "<<calc(c, d)-calc(a, b)<<endl;
	}
}
