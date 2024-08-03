// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct number{
	int n[4];
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int a,b;
	cout<<"0123"<<endl;
	while(cin>>a>>b){
		vector<number> v;
		for(int q=0;q<10;q++){
			for(int w=0;w<10;w++){
				for(int e=0;e<10;e++){
					for(int r=0;r<10;r++){
						if(q!=w&&q!=e&&q!=r&&w!=e&&w!=r&&e!=r){
							v.push_back({q,w,e,r});
						}
					}
				}
			}
		}
		number l;
		l=v.front();
		v.erase(v.begin());
		while(true){
			if(a==4&&b==0)break;
			unsigned int i=0;
			while(1){
				if(i>=v.size())break;
				set<int> cl,cv;
				int ta=0,tb=0;
				for(int q=0;q<4;q++){
					if(l.n[q]==v[i].n[q])ta++;
					cl.insert(l.n[q]);
					cv.insert(v[i].n[q]);
				}
				vector<int> ccm;
				set_intersection(cl.begin(),cl.end(),cv.begin(),cv.end(),inserter(ccm,ccm.begin()));
				tb=ccm.size()-ta;
				if(a==ta&&b==tb){
					i++;
				}else {
					v.erase(v.begin()+i);
				}
			}
			l=v.front();
			for(int q=0;q<4;q++)cout<<l.n[q];
			cout<<endl;
			v.erase(v.begin());
			cin>>a>>b;
		}
		cout<<"0123"<<endl;
	}
}
