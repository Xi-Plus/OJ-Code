// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	priority_queue<long long> v1;
	priority_queue<long long,vector<int>,greater<int>> v2;
	int n;
	bool count=0;
	while(cin>>n){
		count^=1;
		if(v2.size()>v1.size()){
			int t=v2.top();
			v2.pop();
			v1.push(t);
		}
		v1.push(n);
		if(v1.size()>v2.size()){
			int t=v1.top();
			v1.pop();
			v2.push(t);
		}
		if(count){
			cout<<v2.top()<<endl;
		}else {
			cout<<(v1.top()+v2.top())/2<<endl;
		}
	}
}
