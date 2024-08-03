// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		int n;
		cin>>n;
		int v[n][n];
		char c;
		for(int q=0;q<n;q++){
			for(int w=0;w<n;w++){
				cin>>c;
				v[q][w]=c-'0';
			}
		}
		int k;
		string s;
		cin>>k;
		int a,b;
		while(k--){
			cin>>s;
			if(s=="row"){
				cin>>a>>b;
				a--;b--;
				for(int q=0;q<n;q++){
					swap(v[a][q],v[b][q]);
				}
			}else if(s=="col"){
				cin>>a>>b;
				a--;b--;
				for(int q=0;q<n;q++){
					swap(v[q][a],v[q][b]);
				}
			}else if(s=="inc"){
				for(int q=0;q<n;q++){
					for(int w=0;w<n;w++){
						v[q][w]++;
						if(v[q][w]>9)v[q][w]-=10;
					}
				}
			}else if(s=="dec"){
				for(int q=0;q<n;q++){
					for(int w=0;w<n;w++){
						v[q][w]--;
						if(v[q][w]<0)v[q][w]+=10;
					}
				}
			}else {
				for(int q=0;q<n;q++){
					for(int w=q+1;w<n;w++){
						swap(v[q][w],v[w][q]);
					}
				}
			}
		}
		cout<<"Case #"<<cas<<endl;
		for(int q=0;q<n;q++){
			for(int w=0;w<n;w++){
				cout<<v[q][w];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
