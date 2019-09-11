#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, arr[105];
	int t=1;
	while(cin>>n){
		bool ans=true;
		for(int q=0; q<n; q++){
			cin>>arr[q];
			if(arr[q]<1){
				ans=false;
			}
		}
		for(int q=0; q<n-1; q++){
			if(arr[q]>=arr[q+1]){
				ans=false;
			}
		}
		set<int> s;
		for(int q=0; q<n; q++){
			for(int w=q; w<n; w++){
				s.insert(arr[q]+arr[w]);
			}
		}
		cout<<"Case #"<<t++<<": ";
		if(ans&&s.size()==n*(n+1)/2){
			cout<<"It is a B2-Sequence."<<endl;
		}else{
			cout<<"It is not a B2-Sequence."<<endl;
		}
		cout<<endl;
	}
}
