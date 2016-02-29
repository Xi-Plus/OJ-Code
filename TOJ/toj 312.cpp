// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[2][100010],ans[100010];
int n=0;
bool debug=0;
//          0,1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16,17,18
int poss[]={1,2,3,4,5,6,7,8,9,10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int has0[]={1,1,1,1,1,1,1,1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int getposs(int n,int k,int l){
	if(k==l)return poss[n]-has0[n];
	return poss[n];
}
long long solve(int k,int l){
	if(debug)cout<<"solve"<<k<<endl;
	int r=n-1;
	long long ta=1;
	while(l<=r){
		if(debug)cout<<l<<" "<<r<<" "<<v[k][l]<<" "<<v[k][r]<<endl;
		if(l==r){
			if(v[k][l]%2){
				return 0;
			}
			else {
				ans[l]=v[k][l]/2;
				return ta;
			}
		}
		if(v[k][l]==v[k][r]){
			if(debug)cout<<"same"<<endl;
			ta*=getposs(v[k][l],k,l);
//			ans[l]=(v[k][l]+1)/2;
//			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
			continue;
		}
		if(v[k][l]==v[k][r]+11){
			if(debug)cout<<"add 11"<<endl;
			v[k][l]--;
			v[k][l+1]+=10;
			ta*=getposs(v[k][l],k,l);
//			ans[l]=(v[k][l]+1)/2;
//			ans[r]=v[k][l]-ans[l];
			v[k][r]+=10;
			v[k][r-1]--;
			l++;
			r--;
		}
		else if(v[k][l]==v[k][r]+10&&v[k][l]<=18&&l<r-1){
			if(debug)cout<<"add 10"<<endl;
			v[k][r]+=10;
			v[k][r-1]--;
			ta*=getposs(v[k][l],k,l);
//			ans[l]=(v[k][l]+1)/2;
//			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
		}
		else if(v[k][l]==v[k][r]+1&&l<r-1&&v[k][l]>0){
			if(debug)cout<<"add 1"<<endl;
			v[k][l]--;
			v[k][l+1]+=10;
			ta*=getposs(v[k][l],k,l);
//			ans[l]=(v[k][l]+1)/2;
//			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
		}
		else {
			if(debug)cout<<"break"<<endl;
			return 0;
		}
	}
	return ta;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s;
	while(getline(cin,s)){
		n=s.size();
		for(int q=0;q<n;q++){
			v[0][q]=v[1][q]=s[q]-'0';
		}
		v[1][1]+=10;
		long long ans=0,ans0=solve(0,0),ans1=solve(1,1);
		if(v[1][0]==1&&n>1){
			ans+=ans1;
		}
		if(((v[0][0]==1&&v[0][n-1]!=0)||(v[0][0]!=1))){
			ans+=ans0;
		}
		cout<<ans<<endl;
	}
}

