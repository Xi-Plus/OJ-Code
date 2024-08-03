// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,m,k,t;
	while(cin>>n>>m){
		int v[n][m];
		memset(v,0,sizeof(v));
		for(int q=0;q<n;q++){
			cin>>k;
			vector<int> key;
			for(int w=0;w<k;w++){
				cin>>t;
				key.push_back(t-1);
			}
			for(int w=0;w<k;w++){
				cin>>t;
				v[q][key[w]]=t;
			}
		}
		int v2[m][n];
		for(int q=0;q<n;q++){
			for(int w=0;w<m;w++){
				v2[w][q]=v[q][w];
			}
		}
		cout<<m<<" "<<n<<endl;
		for(int q=0;q<m;q++){
			vector<int> key;
			for(int w=0;w<n;w++){
				if(v2[q][w]){
					key.push_back(w);
				}
			}
			int sz=key.size();;
			cout<<sz;
			for(int w=0;w<sz;w++){
				cout<<" "<<key[w]+1;
			}
			cout<<endl;
			for(int w=0;w<sz;w++){
				if(w)cout<<" ";
				cout<<v2[q][key[w]];
			}
			cout<<endl;
		}
	}
}
