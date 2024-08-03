// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[2][100010],ans[100010];
int n=0;
bool debug=1;
bool solve(int k,int l){
	if(debug)cout<<"solve"<<k<<endl;
	int r=n-1;
	while(l<=r){
		if(debug)cout<<l<<" "<<r<<" "<<v[k][l]<<" "<<v[k][r]<<endl;
		if(l==r){
			if(v[k][l]%2){
				return false;
			}
			else {
				ans[l]=v[k][l]/2;
				return true;
			}
		}
		if(v[k][l]==v[k][r]){
			if(debug)cout<<"same"<<endl;
			ans[l]=(v[k][l]+1)/2;
			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
			continue;
		}
		if(v[k][l]==v[k][r]+11){
			if(debug)cout<<"add 11"<<endl;
			v[k][l]--;
			v[k][l+1]+=10;
			ans[l]=(v[k][l]+1)/2;
			ans[r]=v[k][l]-ans[l];
			v[k][r]+=10;
			v[k][r-1]--;
			l++;
			r--;
		}
		else if(v[k][l]==v[k][r]+10&&v[k][l]<=18&&l<r-1){
			if(debug)cout<<"add 10"<<endl;
			v[k][r]+=10;
			v[k][r-1]--;
			ans[l]=(v[k][l]+1)/2;
			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
		}
		else if(v[k][l]==v[k][r]+1&&l<r-1&&v[k][l]>0){
			if(debug)cout<<"add 1"<<endl;
			v[k][l]--;
			v[k][l+1]+=10;
			ans[l]=(v[k][l]+1)/2;
			ans[r]=v[k][l]-ans[l];
			l++;
			r--;
		}
		else {
			if(debug)cout<<"break"<<endl;
			return false;
		}
	}
	return true;
}
void output(int s){
	for(int q=s;q<n;q++)cout<<ans[q];
	cout<<endl;
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
		if(v[1][0]==1&&n>1&&solve(1,1)){
			output(1);
		}else if(((v[0][0]==1&&v[0][n-1]!=0)||(v[0][0]!=1))&&solve(0,0)){
			output(0);
		}else {
			cout<<0<<endl;
		}
	}
}

