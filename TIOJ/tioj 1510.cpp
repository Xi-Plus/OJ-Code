// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Color{;
	int c[3]={0,0,0},cnt=0;
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,x1,y1,x2,y2;
	int input[100][7];
	vector<int> xlist,ylist;
	vector<int>::iterator it;
	cin>>n;
	for(int q=0;q<n;q++){
		for(int w=0;w<7;w++){
			cin>>input[q][w];
		}
		if(input[q][0]>input[q][2]) swap(input[q][0],input[q][2]);
		if(input[q][1]>input[q][3]) swap(input[q][1],input[q][3]);
		xlist.push_back(input[q][0]);
		ylist.push_back(input[q][1]);
		xlist.push_back(input[q][2]);
		ylist.push_back(input[q][3]);
	}
	sort(xlist.begin(),xlist.end());
	it=unique(xlist.begin(),xlist.end());
	xlist.resize(it-xlist.begin());
	sort(ylist.begin(),ylist.end());
	it=unique(ylist.begin(),ylist.end());
	ylist.resize(it-ylist.begin());
	Color v[200][200];
	for(int q=0;q<n;q++){
		int xs,xe,ys,ye;
		xs=lower_bound(xlist.begin(),xlist.end(),input[q][0])-xlist.begin();
		xe=lower_bound(xlist.begin(),xlist.end(),input[q][2])-xlist.begin();
		ys=lower_bound(ylist.begin(),ylist.end(),input[q][1])-ylist.begin();
		ye=lower_bound(ylist.begin(),ylist.end(),input[q][3])-ylist.begin();
		for(int w=xs;w<xe;w++){
			for(int e=ys;e<ye;e++){
				for(int r=0;r<3;r++){
					v[w][e].c[r]+=input[q][r+4];
				}
				v[w][e].cnt++;
			}
		}
	}
	int xsz,ysz;
	xsz=xlist.size();
	ysz=ylist.size();
	map<int,int> colorcnt;
	for(int q=0;q<xsz-1;q++){
		for(int w=0;w<ysz-1;w++){
			if(v[q][w].cnt==0)continue;
			int avg[3];
			for(int e=0;e<3;e++){
				avg[e]=v[q][w].c[e]/v[q][w].cnt;
				if(v[q][w].c[e]%v[q][w].cnt) avg[e]++;
			}
			colorcnt[avg[0]*1000000+avg[1]*1000+avg[2]]+=(xlist[q+1]-xlist[q])*(ylist[w+1]-ylist[w]);
		}
	}
	int maxcolor,maxsize=0;
	for(auto i:colorcnt){
		if(i.second>maxsize&&i.first!=0){
			maxcolor=i.first;
			maxsize=i.second;
		}
	}
	cout<<maxcolor/1000000<<" ";maxcolor%=1000000;
	cout<<maxcolor/1000<<" ";maxcolor%=1000;
	cout<<maxcolor<<endl;
}
