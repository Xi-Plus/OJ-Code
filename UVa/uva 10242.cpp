#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double x[4], y[4];
	cout<<fixed<<setprecision(3);
	while(cin>>x[0]>>y[0]){
		for(int q=1; q<4; q++){
			cin>>x[q]>>y[q];
		}
		bool c=false;
		for(int q=0; q<2; q++){
			for(int w=2; w<4; w++){
				if(x[q]==x[w]&&y[q]==y[w]){
					c=true;
					cout<<x[0]+x[1]+x[2]+x[3]-x[q]*3<<" "<<y[0]+y[1]+y[2]+y[3]-y[q]*3<<endl;
					break;
				}
			}
			if(c){
				break;
			}
		}
	}
}
