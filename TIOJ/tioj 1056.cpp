// By xiplus
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int v[3][3];
	char temp;
	bool x=1;
	int count[3]={0,0,0};
	int win[2]={0,0};
	for(int q=0;q<3;q++){
		for(int w=0;w<3;w++){
			cin>>temp;
			switch(temp){
				case 'O':	v[q][w]=0;break;
				case 'X':	v[q][w]=1;break;
				case '.':	v[q][w]=2;break;
				default:	x=0;goto E;
			}
			count[v[q][w]]++;
		}
	}
	for(int q=0;q<3;q++)
		if(v[q][0]==v[q][1]&&v[q][1]==v[q][2])
			win[v[q][0]]++;
	for(int q=0;q<3;q++)
		if(v[0][q]==v[1][q]&&v[1][q]==v[2][q])
			win[v[0][q]]++;
	if(v[0][0]==v[1][1]&&v[1][1]==v[2][2])
		win[v[0][0]]++;
	if(v[0][2]==v[1][1]&&v[1][1]==v[2][0])
		win[v[0][2]]++;
	if(win[0]*win[1]!=0){
		x=0;
		goto E;
	}
	if(count[0]==count[1]+1){
		if(win[1]!=0){
			x=0;
		}
	}else if(count[0]==count[1]){
		if(win[0]!=0){
			x=0;
		}
	}else {
		x=0;
	}
	E:
	if(x)cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
}
