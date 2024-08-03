// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int v[4][n][n];
	for(int q=0;q<2;q++){
		for(int w=0;w<n;w++){
			for(int e=0;e<n;e++){
				cin>>v[q][w][e];1
			}
		}
	}
		for(int w=0;w<n;w++){
			for(int e=0;e<n;e++){
				cin>>v[2][w][e];
//				v[3][w][e]=(v[0][w][e]+v[1][w][e]+v[2][w][e]);
			}
		}
	bool G=0,I[2]={0,0};
	int D[2]={0,1};
	// 0 1
	// 3 2
	char c;
	while(cin>>c){
		switch(c){
			case 'G': G=true; break;
			case 'I': I[G]=1-I[G]; break;
			case 'R':
				D[0]++;D[0]&=3;
				D[1]++;D[1]&=3;
				break;
			case 'H':
				D[0]=(D[0]&2)|(D[0]^1);
				D[1]=(D[1]&2)|(D[1]^1);
				break;
			case 'V':
				D[0]^=3;
				D[1]^=3;
		}
	}
	int ix,iy,dx,dy;
	bool f; // | false - true
	if(D[0]==0) ix=0,iy=0,dx=1,dy=1,f=D[1]==1;
	else if(D[0]==1) ix=0,iy=n-1,dx=1,dy=-1,f=D[1]==0;
	else if(D[1]==2) ix=n-1,iy=n-1,dx=-1,dy=-1,f=D[1]==3;
	else if(D[1]==3) ix=n-1,iy=0,dx=-1,dy=1,f=D[1]==2;
//	cout<<G<<" "<<I<<" "<<ix<<" "<<iy<<" "<<dx<<" "<<dy<<" "<<f<<endl;
	for(int q=0;q<3;q++){
		int tx=ix,ty=iy;
		while(0<=tx&&tx<n&&0<=ty&&ty<n){
			bool space=false;
			while(0<=tx&&tx<n&&0<=ty&&ty<n){
				int tans;
				if(G){
					if(I[0]){
						v[0][tx][ty]=255-v[0][tx][ty];
						v[1][tx][ty]=255-v[1][tx][ty];
						v[2][tx][ty]=255-v[2][tx][ty];
					}
					tans=(v[0][tx][ty]+v[1][tx][ty]+v[3][tx][ty])/3.0;
					if(I[1])tans=255-tans;
				}else {
					tans=v[q][tx][ty];
					if(I[0]^I[1]) tans=255-tans;
				}
				if(I[1]) tans=255-tans;
				if(space) cout<<" ";
				cout<<tans;
				space=true;
				if(f) ty+=dy;
				else tx+=dx;
			}
			cout<<endl;
			if(f) ty=iy,tx+=dx;
			else tx=ix,ty+=dy;
		}
		if(q!=2)cout<<endl;
	}
}
