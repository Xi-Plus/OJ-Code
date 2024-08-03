// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string a,b;
	cin>>a>>b;
	int sa=a.size(),sb=b.size(),ans=0,l=sa-sb+1;
	for(int q=0;q<l;q++){
//		cout<<q<<endl;
		bool x=1;
		for(int w=0;w<sb;w++){
			if(a[q+w]!=b[w]){
				x=0;
				break;
			}
		}
		if(x){
			ans++;
			q=q+sb-1;
		}
	}
	cout<<ans<<endl;
}

