#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d;
	while(cin>>a>>b>>c>>d, a||b||c||d){
		int ans=1080;
		cout<<1080+9*(a-b<0?a-b+40:a-b)+9*(c-b<0?c-b+40:c-b)+9*(c-d<0?c-d+40:c-d)<<endl;
	}
}
