// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	int a,b;
	bool visit;
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t,n;
	cin>>t;
	int lsz,rsz;
	for(int cas=1;cas<=t;cas++){
		cin>>lsz;
		vector<int> l;
		for(int q=0;q<lsz;q++){
			cin>>n;
			l.push_back(n);
		}
		cin>>rsz;
		vector<int> r;
		for(int q=0;q<rsz;q++){
			cin>>n;
			r.push_back(n);
		}
		vector<T> v;
		for(int q=0;q<lsz;q++){
			for(int w=0;w<rsz;w++){
				if(l[q]==0)continue;
				if(r[w]%l[q]==0){
					v.push_back({l[q],r[w],false});
				}
			}
		}
		cout<<"Case #"<<cas<<": "<<min(li.size(),ri.size())<<endl;
	}
}
