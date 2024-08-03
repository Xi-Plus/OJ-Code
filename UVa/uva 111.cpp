// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int v[21];
int LIS(){
	vector<int> lis;
	lis.push_back(v[1]);
	for(int q=2;q<=n;q++){
		if(v[q]>lis.back()){
			lis.push_back(v[q]);
		}else {
			lis[lower_bound(lis.begin(),lis.end(),v[q])-lis.begin()]=v[q];
		}
	}
	return lis.size();
}
void flip(int arr[],int n){
	int temp[n+1];
	for(int q=1;q<=n;q++){
		temp[arr[q]]=q;
	}
	for(int q=1;q<=n;q++){
		arr[q]=temp[q];
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int k;
	cin>>n;
	int temp[n+1],ans[n+1];
	for(int q=1;q<=n;q++){
		cin>>temp[q];
	}
	flip(temp,n);
	for(int q=1;q<=n;q++){
		ans[temp[q]]=q;
	}
	while(cin>>temp[1]){
		for(int q=2;q<=n;q++){
			cin>>temp[q];
		}
		flip(temp,n);
		for(int q=1;q<=n;q++){
			v[q]=ans[temp[q]];
		}
		cout<<LIS()<<endl;
	}
}
