// By KRT girl xiplus
#include <bits/stdc++.h>
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//    cin.tie(0);
	int n,a,b,c;
	while(cin>>n,n){
		int v[n];
		for(int q=0;q<n;q++)cin>>v[q];
		c=0;
		for(int q=0;q<n-1;q++){
			for(int w=q+1;w<n;w++){
				a=v[q];
				b=v[w];
				while((a%=b)&&(b%=a));
				if(a+b==1)c++;
			}
		}
		if(c==0)cout<<"No estimate for this data set."<<endl;
		else {
			double ans=6.0*(n*(n-1)/2)/c;
			ans=sqrt(ans);
			cout<<fixed<<setprecision(6)<<ans<<endl;
		}
	}
}