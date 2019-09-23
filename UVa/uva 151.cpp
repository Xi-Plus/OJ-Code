#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	bool v[105];
	while(cin>>n, n){
		int m=0;
		while(true){
			m++;
			memset(v, 0, sizeof(v));
			v[0]=1;
			int remain=n-2, i=0;
			while(remain){
				for(int q=0; q<m;){
					i++;
					i%=n;
					if(!v[i]){
						q++;
					}
				}
				v[i]=1;
				remain--;
			}
			if(v[12]==0){
				break;
			}
		}
		cout<<m<<endl;
	}
}
