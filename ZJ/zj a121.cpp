#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool nisp[10010]={false};
int p[10000],k=0;
bool checkp(int n){
	if(n==2||n==3)return 1;
	else if((n-1)%6&&(n+1)%6)return 0;
	else if(n<=10010){
		if(binary_search(p,p+k,n))return 1;
		else return 0;
	}else{
		bool x=0;
		for(int q=0;q<k&&p[q]*p[q]<=n;q++){
			if(n%p[q]==0){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	nisp[0]=nisp[1]=true;
	int i=2,j;
	while(i<10010){
		if(!nisp[i]){
			p[k++]=i;
			j=i*2;
			while(j<10010){
				nisp[j]=true;
				j+=i;
			}
		}
		i++;
	}
	int a,b;
	while(cin>>a>>b){
		if(a>b)swap(a,b);
		int ans=0;
		for(int q=a;q<=b;q++){
			ans+=checkp(q);
		}
		cout<<ans<<endl;
	}
}
