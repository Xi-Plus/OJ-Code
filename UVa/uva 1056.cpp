#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int BIGDIS = INT_MAX/2;
int dis[55][55];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int P, R;
	string s1, s2;
	int t=1;
	while(cin>>P>>R, P||R){
		map<string, int> pid;
		int pidcnt=0;
		for(int q=0; q<P; q++){
			for(int w=0; w<P; w++){
				dis[q][w]=BIGDIS;
			}
		}
		for(int q=0; q<P; q++){
			dis[q][q]=0;
		}
		while(R--){
			cin>>s1>>s2;
			if(pid.find(s1)==pid.end()){
				pid[s1]=pidcnt++;
			}
			if(pid.find(s2)==pid.end()){
				pid[s2]=pidcnt++;
			}
			dis[pid[s1]][pid[s2]]=1;
			dis[pid[s2]][pid[s1]]=1;
		}
		for(int k=0; k<P; k++){
			for(int i=0; i<P; i++){
				for(int j=0; j<P; j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		int maxdis=-1;
		for(int q=0; q<P; q++) {
			for(int w=q+1; w<P; w++){
				maxdis=max(maxdis, dis[q][w]);
			}
		}
		if(maxdis==BIGDIS){
			cout<<"Network "<<t++<<": DISCONNECTED"<<endl;
		}else{
			cout<<"Network "<<t++<<": "<<maxdis<<endl;
		}
		cout<<endl;
	}
}
