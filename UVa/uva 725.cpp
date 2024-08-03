// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> get_each_dig(int n){
	vector<int> v;
	v.push_back(n/10000);n%=10000;
	v.push_back(n/1000);n%=1000;
	v.push_back(n/100);n%=100;
	v.push_back(n/10);n%=10;
	v.push_back(n);
	return v;
}
bool check_vaild(vector<int>a,vector<int>b){
	bool x[10]={false};
	for(auto i:a){
		x[i]=1;
	}
	for(auto i:b){
		x[i]=1;
	}
	int t=0;
	for(int i=0;i<10;i++){
		t+=x[i];
	}
	return t==10;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	bool wrap=false;
	while(cin>>n,n){
		if(wrap) cout<<endl;
		bool x=true;
		for(int i=01234;i*n<=98765;i++){
			if(check_vaild(get_each_dig(i*n),get_each_dig(i))){
				cout<<i*n<<" / "<<(i<10000?"0":"")<<i<<" = "<<n<<endl;
				x=false;
			}
		}
		if(x){
			cout<<"There are no solutions for "<<n<<"."<<endl;
		}
		wrap=true;
	}
}

