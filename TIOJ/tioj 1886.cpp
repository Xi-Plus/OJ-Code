// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmpwait(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<pair<int,int>> wait;
		int a,b;
		for(int q=0;q<N;q++){
			cin>>a>>b;
			wait.push_back(make_pair(a,b));
		}
		sort(wait.begin(),wait.end(),cmpwait);
		int Q;
		cin>>Q;
		int K;
		while(Q--){
			cin>>K;
			vector<int> k;
			for(int q=0;q<K;q++){
				cin>>a;
				k.push_back(a);
			}
			sort(k.begin(),k.end());
			priority_queue<int,vector<int>,greater<int>> work;
			bool x=1;
			int waitkey=0;
			for(int q=0;q<K;q++){
	//			cout<<"work "<<k[q]<<endl;
				for(;waitkey<N&&wait[waitkey].first<=k[q];waitkey++){
					work.push(wait[waitkey].second);
	//				cout<<"put in "<<wait[waitkey].second<<endl;
				}
				while(!work.empty()&&work.top()<k[q])work.pop();
				if(work.size()<k[q]){
					x=0;
					break;
				}else{
					for(int w=0;w<k[q];w++)work.pop();
	//				cout<<"pop "<<k[q]<<endl;
				}
			}
			cout<<x<<endl;
		}
	}
}
