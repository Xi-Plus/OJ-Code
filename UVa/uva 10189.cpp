#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char arr[105][105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, cnt=1;
	while(cin>>n>>m, n&&m){
		if(cnt>1){
			cout<<endl;
		}
		memset(arr, ' ', sizeof(arr));
		for(int q=1; q<=n; q++){
			for(int w=1; w<=m; w++){
				cin>>arr[q][w];
			}
		}
		for(int q=1; q<=n; q++){
			for(int w=1; w<=m; w++){
				if(arr[q][w]=='.'){
					int sum=0;
					for(int e=-1; e<=1; e++){
						for(int r=-1; r<=1; r++){
							if(arr[q+e][w+r]=='*'){
								sum++;
							}
						}
					}
					arr[q][w]=sum+'0';
				}
			}
		}
		cout<<"Field #"<<cnt++<<":"<<endl;
		for(int q=1; q<=n; q++){
			for(int w=1; w<=m; w++){
				cout<<arr[q][w];
			}
			cout<<endl;
		}
	}
}
