// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m,n;
	cin>>m>>n;
	vector<vector<int>>v[m+1];
	int a,b;
	while(cin>>a>>b){
		for(int q=2;q<m;q++){
			int sz=v[q].size();
			for(int w=0;w<sz-1;w++){
				for(int e=w+1;e<sz;e++){
					vector<int>dif(q);
					vector<int>::iterator it;
					int ta,tb;
					it=set_difference(v[q][w].begin(),v[q][w].end(),v[q][e].begin(),v[q][e].end(),dif.begin());
					if(it-dif.begin()!=1)continue;
					ta=dif[0];
					it=set_difference(v[q][e].begin(),v[q][e].end(),v[q][w].begin(),v[q][w].end(),dif.begin());
					if(it-dif.begin()!=1)continue;
					tb=dif[0];
					vector<int>temp=v[q][w];
					if(a==ta&&b==tb){
						temp.push_back(b);
					}else if(a==tb&&b==ta){
						temp.push_back(a);
					}else {
						continue;
					}
					sort(temp.begin(),temp.end());
					v[q+1].push_back(temp);
				}
			}
		}
		vector<int>temp;
		temp.push_back(a);
		temp.push_back(b);
		sort(temp.begin(),temp.end());
		v[2].push_back(temp);
	}
	vector<int> used;
	long long ans=1;
	int minroom=0;
	for(int q=m;q>=2;q--){
		if(v[q].size()!=0){
			minroom=max(minroom,q);
		}
		int sz=v[q].size();
		for(int w=0;w<sz;w++){
			vector<int> sett(q);
			vector<int>::iterator it;
			int difsz,intsz;
			it=set_intersection(v[q][w].begin(),v[q][w].end(),used.begin(),used.end(),sett.begin());
			intsz=n-(it-sett.begin());
			Debug(clog<<(it-sett.begin())<<endl;)
			it=set_difference(v[q][w].begin(),v[q][w].end(),used.begin(),used.end(),sett.begin());
			sett.resize(it-sett.begin());
			difsz=sett.size();
			for(auto i:sett){
				used.push_back(i);
			}
			sort(used.begin(),used.end());
			difsz=sett.size();
			for(int e=intsz;e>=intsz-difsz+1;e--){
				ans*=e;
			}
			if(used.size()==m)break;
		}
		if(used.size()==m)break;
	}
	int sz=m-used.size();
	while(sz--){
		ans*=n;
	}
	if(minroom>n){
		cout<<0<<endl;
	}else {
		cout<<ans<<endl;
	}
	cout<<max(minroom,1)<<endl;
}
