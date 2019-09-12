#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y, dx, dy;
	char dir;
	string s;
	cin>>n>>m;
	bool danger[n+1][m+1];
	memset(danger, false, sizeof(danger));
	while(cin>>x>>y>>dir){
		switch(dir){
			case 'N': dx=0; dy=1; break;
			case 'S': dx=0; dy=-1; break;
			case 'W': dx=-1; dy=0; break;
			case 'E': dx=1; dy=0; break;
		}
		cin.ignore();
		getline(cin, s);
		bool lost=false;
		for(char c:s){
			if(c=='L'){
				if(dx==0&&dy==1){
					dx=-1; dy=0;
				}else if(dx==0&&dy==-1){
					dx=1; dy=0;
				}else if(dx==-1&&dy==0){
					dx=0; dy=-1;
				}else{
					dx=0; dy=1;
				}
			}else if(c=='R'){
				if(dx==0&&dy==1){
					dx=1; dy=0;
				}else if(dx==0&&dy==-1){
					dx=-1; dy=0;
				}else if(dx==-1&&dy==0){
					dx=0; dy=1;
				}else{
					dx=0; dy=-1;
				}
			}else{
				if(x+dx<0||x+dx>n||y+dy<0||y+dy>m){
					if(!danger[x][y]){
						lost=true;
						danger[x][y]=true;
						break;
					}
				}else{
					x+=dx;
					y+=dy;
				} 
			}
		}
		cout<<x<<" "<<y<<" ";
		if(dx==0&&dy==1){
			cout<<"N";
		}else if(dx==0&&dy==-1){
			cout<<"S";
		}else if(dx==-1&&dy==0){
			cout<<"W";
		}else{
			cout<<"E";
		}
		if(lost){
			cout<<" LOST";
		}
		cout<<endl;
	}
}
