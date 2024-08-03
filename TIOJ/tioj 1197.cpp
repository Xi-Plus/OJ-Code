// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
#define Debug(A)
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m,n;
	cin>>m>>n;
	vector<vector<int>>v[m+1];
	int a,b;
	while(cin>>a>>b){
		Debug(clog<<"input "<<a<<" "<<b<<endl;)
		for(int q=2;q<m;q++){
			Debug(clog<<"for m="<<q<<endl;)
			int sz=v[q].size();
			Debug(clog<<"sz="<<sz<<endl;)
			for(int w=0;w<sz-1;w++){
				Debug(clog<<"for w="<<w<<endl;)
				for(int e=w+1;e<sz;e++){
					Debug(clog<<"for e="<<e<<endl;
					clog<<"vector w: ";
					for(auto i:v[q][w]){
						clog<<i<<" ";
					}
					clog<<endl;
					clog<<"vector e: ";
					for(auto i:v[q][e]){
						clog<<i<<" ";
					}
					clog<<endl;)
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
					Debug(clog<<"add "<<q+1<<": ";
					for(auto i:temp){
						clog<<i<<" ";
					}
					clog<<endl;)
				}
			}
		}
		vector<int>temp;
		temp.push_back(a);
		temp.push_back(b);
		sort(temp.begin(),temp.end());
		v[2].push_back(temp);
		Debug(clog<<"add 2: ";
		for(auto i:temp){
			clog<<i<<" ";
		}
		clog<<endl;)
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
			Debug(clog<<"check: ";
			for(auto i:v[q][w]){
				clog<<i<<" ";
			}
			clog<<" in ";
			for(auto i:used){
				clog<<i<<" ";
			}
			clog<<endl;)
			vector<int> sett(q);
			vector<int>::iterator it;
			int difsz,intsz;
			it=set_intersection(v[q][w].begin(),v[q][w].end(),used.begin(),used.end(),sett.begin());
			intsz=n-(it-sett.begin());
			Debug(clog<<(it-sett.begin())<<endl;)
			it=set_difference(v[q][w].begin(),v[q][w].end(),used.begin(),used.end(),sett.begin());
			sett.resize(it-sett.begin());
			difsz=sett.size();
			Debug(clog<<difsz<<" "<<intsz<<endl;
			clog<<"add: ";)
			for(auto i:sett){
				Debug(clog<<i<<" ";)
				used.push_back(i);
			}
			Debug(clog<<endl;)
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
