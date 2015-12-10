#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int q[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>q[i][j];
		}
	}
	int m;
	cin>>m;
	int p[m][m];
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool find=true;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(q[i+k][j+l]!=p[k][l]){
						find=false;
						goto End;
					}
				}
			}
			End:
			if(find){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
}
