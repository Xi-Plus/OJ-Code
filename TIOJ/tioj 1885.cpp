// By KRT girl xiplus
#include <bits/stdc++.h>
//#include "lib1885.h"
#define endl '\n'
using namespace std;
int getMinVal(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q){
	return min(min(get<0>(q).second,get<1>(q).second),get<2>(q).second);
}
int getMaxVal(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q){
	return max(max(get<0>(q).second,get<1>(q).second),get<2>(q).second);
}
int getMinKey(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q){
	int minw=getMinVal(q);
	if(get<0>(q).second==minw)return get<0>(q).first;
	if(get<1>(q).second==minw)return get<1>(q).first;
	if(get<2>(q).second==minw)return get<2>(q).first;
}
int getMidKey(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q){
	int minw=getMinVal(q);
	int maxw=getMaxVal(q);
	if(get<0>(q).second!=minw&&get<0>(q).second!=maxw)return get<0>(q).first;
	if(get<1>(q).second!=minw&&get<1>(q).second!=maxw)return get<1>(q).first;
	if(get<2>(q).second!=minw&&get<2>(q).second!=maxw)return get<2>(q).first;
}
int getMaxKey(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q){
	int maxw=getMaxVal(q);
	if(get<0>(q).second==maxw)return get<0>(q).first;
	if(get<1>(q).second==maxw)return get<1>(q).first;
	if(get<2>(q).second==maxw)return get<2>(q).first;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
int getNextKey(tuple<pair<int,int>,pair<int,int>,pair<int,int>>q,int dw){
	int maxw=getMaxVal(q);
	if(maxw<dw){
		return getMinKey(q);
	}
	vector<pair<int,int>> v;
	if(get<0>(q).second>dw) v.push_back(get<0>(q));
	if(get<1>(q).second>dw) v.push_back(get<1>(q));
	if(get<2>(q).second>dw) v.push_back(get<2>(q));
	sort(v.begin(),v.end(),cmp);
	return v[0].first;
}
struct Rule{
	int id;
	tuple<int,int,int> par;
	int d;
};
/***Judge***/ 

int Init(){
	return 1000;
}
int realwei[7];
void orderCoins(){
	vector<int> wei;
	wei.push_back(11);wei.push_back(12);wei.push_back(13);
	wei.push_back(14);wei.push_back(15);wei.push_back(16);
	for(int q=1;q<=6;q++){
		int t=rand()%wei.size();
		realwei[q]=wei[t];
		wei.erase(wei.begin()+t,wei.begin()+t+1);
	}
	cout<<"Ans wei ";
	for(int q=1;q<=6;q++){
		cout<<realwei[q]<<" ";
	}
	cout<<endl;
}
int usecnt=0;
int getLightest(int A,int B,int C){
	cout<<"count= "<<++usecnt<<endl;
//	cout<<"Ask min "<<A<<" "<<B<<" "<<C<<" "<<realwei[A]<<" "<<realwei[B]<<" "<<realwei[C]<<endl;
	return getMinKey(make_tuple(make_pair(A,realwei[A]),
								make_pair(B,realwei[B]),
								make_pair(C,realwei[C])));
}
int getMedian(int A,int B,int C){
	cout<<"count= "<<++usecnt<<endl;
//	cout<<"Ask mid "<<A<<" "<<B<<" "<<C<<" "<<realwei[A]<<" "<<realwei[B]<<" "<<realwei[C]<<endl;
	return getMidKey(make_tuple(make_pair(A,realwei[A]),
								make_pair(B,realwei[B]),
								make_pair(C,realwei[C])));
}
int getHeaviest(int A,int B,int C){
	cout<<"count= "<<++usecnt<<endl;
//	cout<<"Ask max "<<A<<" "<<B<<" "<<C<<" "<<realwei[A]<<" "<<realwei[B]<<" "<<realwei[C]<<endl;
	return getMaxKey(make_tuple(make_pair(A,realwei[A]),
								make_pair(B,realwei[B]),
								make_pair(C,realwei[C])));
}
int getNextLightest(int A,int B,int C,int D){
	cout<<"count= "<<++usecnt<<endl;
//	cout<<"Ask next "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<realwei[A]<<" "<<realwei[B]<<" "<<realwei[C]<<" "<<realwei[D]<<endl;
	return getNextKey(make_tuple(make_pair(A,realwei[A]),
							make_pair(B,realwei[B]),
							make_pair(C,realwei[C])),realwei[D]);
}
bool answer(int ans[]){
	vector<pair<int,int>> v;
	for(int q=1;q<=6;q++){
		v.push_back(make_pair(q,realwei[q]));
	}
	sort(v.begin(),v.end(),cmp);
	bool x=true;
	for(int q=0;q<6;q++){
//		cout<<v[q].first<<" "<<ans[q]<<endl;
		if(v[q].first!=ans[q]){
			x=false;
		}
	}
	cout<<x<<endl;
	return x;
}
/***Judge***/ 
Rule bestrule[7][730];
vector<vector<int>> realans;
int limit[]={0,1,3,9,27,81,243};
bool dfs(vector<vector<int>> weilist,int dfscnt,int bestruleid){
	if(dfscnt==0){
		if(weilist.size()<=1){
			if(weilist.size()==1){
				realans[bestruleid]=weilist[0];
			}
			return true;
		}else {
			return false;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=i+1;j<=5;j++){
			for(int k=j+1;k<=6;k++){
				for(int ruleid=1;ruleid<=3;ruleid++){
					int rulecnt[3]={0,0,0};
					vector<vector<int>> nextans[3];
					for(auto ans:weilist){
						int res;
						if(ruleid==1){
							res=getMinKey(make_tuple(make_pair(i,ans[i]),
												make_pair(j,ans[j]),
												make_pair(k,ans[k])));
						}else if(ruleid==2){
							res=getMidKey(make_tuple(make_pair(i,ans[i]),
												make_pair(j,ans[j]),
												make_pair(k,ans[k])));
						}else if(ruleid==3){
							res=getMaxKey(make_tuple(make_pair(i,ans[i]),
												make_pair(j,ans[j]),
												make_pair(k,ans[k])));
						}else assert(0);
						if(res==i){
							rulecnt[0]++;
							nextans[0].push_back(ans);
						}else if(res==j){
							rulecnt[1]++;
							nextans[1].push_back(ans);
						}else if(res==k){
							rulecnt[2]++;
							nextans[2].push_back(ans);
						}else assert(0);
					}
					if(rulecnt[0]<=limit[dfscnt]&&rulecnt[1]<=limit[dfscnt]&&rulecnt[2]<=limit[dfscnt]){
						if(dfs(nextans[0],dfscnt-1,bestruleid*3)&&dfs(nextans[1],dfscnt-1,bestruleid*3+1)&&dfs(nextans[2],dfscnt-1,bestruleid*3+2)){
							bestrule[dfscnt][bestruleid]={ruleid,make_tuple(i,j,k),-1};
							return true;
						}
					}
				}
				for(int d=1;d<=6;d++){
					if (d!=i&&d!=j&&d!=k){
						int rulecnt[3]={0,0,0};
						vector<vector<int>> nextans[3];
						for(auto ans:weilist){
							int res=getNextKey(make_tuple(make_pair(i,ans[i]),
												make_pair(j,ans[j]),
												make_pair(k,ans[k])),ans[d]);
							if(res==i){
								rulecnt[0]++;
								nextans[0].push_back(ans);
							}else if(res==j){
								rulecnt[1]++;
								nextans[1].push_back(ans);
							}else if(res==k){
								rulecnt[2]++;
								nextans[2].push_back(ans);
							}else assert(0);
						}
						if(rulecnt[0]<=limit[dfscnt]&&rulecnt[1]<=limit[dfscnt]&&rulecnt[2]<=limit[dfscnt]){
							if(dfs(nextans[0],dfscnt-1,bestruleid*3)&&dfs(nextans[1],dfscnt-1,bestruleid*3+1)&&dfs(nextans[2],dfscnt-1,bestruleid*3+2)){
								bestrule[dfscnt][bestruleid]={4,make_tuple(i,j,k),d};
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T=Init();
	vector<int> wei;wei.push_back(0);
	wei.push_back(21);wei.push_back(22);wei.push_back(23);
	wei.push_back(24);wei.push_back(25);wei.push_back(26);
	vector<vector<int>> weilist;
	while (wei[0]==0) {
		bool x[7]={false};
		for(int q=1;q<=6;q++) x[wei[q]-20]=1;
		int s=0;
		for(int q=1;q<=6;q++) s+=x[q];
		if (s==6) weilist.push_back(wei);
		wei[6]++;
		for (int i=6; i >= 1; i--) {
			if (wei[i]>26) {
				wei[i]=21;
				wei[i-1]++;
			}
		}
	}
	realans.resize(730);
	dfs(weilist,6,0);
	while(T--){
		orderCoins();
		int ruleid=0;
		for(int q=6;q>=1;q--){
			int res;
			if(bestrule[q][ruleid].id==1){
				res=getLightest(get<0>(bestrule[q][ruleid].par),get<1>(bestrule[q][ruleid].par),get<2>(bestrule[q][ruleid].par));
			}else if(bestrule[q][ruleid].id==2){
				res=getMedian(get<0>(bestrule[q][ruleid].par),get<1>(bestrule[q][ruleid].par),get<2>(bestrule[q][ruleid].par));
			}else if(bestrule[q][ruleid].id==3){
				res=getHeaviest(get<0>(bestrule[q][ruleid].par),get<1>(bestrule[q][ruleid].par),get<2>(bestrule[q][ruleid].par));
			}else if(bestrule[q][ruleid].id==4){
				res=getNextLightest(get<0>(bestrule[q][ruleid].par),get<1>(bestrule[q][ruleid].par),get<2>(bestrule[q][ruleid].par),
									bestrule[q][ruleid].d);
			}
			if(res==get<0>(bestrule[q][ruleid].par))ruleid=ruleid*3;
			else if(res==get<1>(bestrule[q][ruleid].par))ruleid=ruleid*3+1;
			else ruleid=ruleid*3+2;
		}
		vector<pair<int,int>> v;
		for(int q=1;q<=6;q++){
			v.push_back(make_pair(q,realans[ruleid][q]));
		}
		sort(v.begin(),v.end(),cmp);
		int a[6];
		for(int q=0;q<6;q++){
			a[q]=v[q].first;
		}
		answer(a);
	}
}
