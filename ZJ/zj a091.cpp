// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	deque<int> v;
	int k,n;
	while(cin>>k){
		if(k==1){
			cin>>n;
			v.push_back(n);
			sort(v.begin(),v.end());
		}else if(k==2){
			cout<<v.back()<<endl;
			v.pop_back();
		}else {
			cout<<v.front()<<endl;
			v.pop_front();
		}
	}
}
