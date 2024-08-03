// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct probinfo{
	long long T[3];
	int used=0;
};
struct costlist{
	long long cost;
	long long costsum;
	long long score;
	long long probid;
	long long diff;
};
bool cmp_sort(costlist a,costlist b){
	if(a.cost==b.cost){
		if(a.score==b.score){
			return a.diff<b.diff;
		}
		return a.score<b.score;
	}
	return a.cost<b.cost;
}
//bool cmp_find1(costlist x,long long y){
//	return x.scoresum<y;
//}
//bool cmp_find2(long long y,costlist x){
//	return x.scoresum>y;
//}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,t;
	cin>>n>>t;
	probinfo prob[n];
	costlist costtemp[n*2];
	for(int q=0;q<n;q++){
		cin>>prob[q].T[2]>>prob[q].T[1];
		prob[q].T[0]=prob[q].T[2]-prob[q].T[1];
		costtemp[q*2]={prob[q].T[1],prob[q].T[1],1,q,prob[q].T[0]};
		costtemp[q*2+1]={prob[q].T[0],prob[q].T[0],2,q,prob[q].T[0]};
	}
	sort(costtemp,costtemp+n*2,cmp_sort);
	costlist cost[n*2];
	int index=0;
	for(int q=0;q<n*2;q++){
		if(costtemp[q].score==1){
			cost[index]=costtemp[q];
			index++;
			if(prob[costtemp[q].probid].used==2){
				cost[index]={prob[costtemp[q].probid].T[0],prob[costtemp[q].probid].T[0],2,costtemp[q].probid,prob[costtemp[q].probid].T[0]};
				index++;
			}
			prob[costtemp[q].probid].used=1;
		} else {
			if(prob[costtemp[q].probid].used==1){
				cost[index]=costtemp[q];
				index++;
			} else {
				prob[costtemp[q].probid].used=2;
			}
		}
	}
	for(int q=1;q<n*2;q++){
		cost[q].costsum+=cost[q-1].costsum;
	}
//	for(int q=0;q<n*2;q++){
//		cout<<q<<"\t"<<cost[q].cost<<"\t"<<cost[q].costsum<<"\t"<<cost[q].score<<"\t"<<cost[q].probid<<endl;
//	}
	long long sea_l=0,sea_r=n*2,score;
	while(true){
		score=(sea_l+sea_r)/2+1;
//		cout<<"sea: "<<sea_l<<" "<<sea_r<<" "<<score<<endl;
		if(sea_l==sea_r)break;
		long long mincost=cost[score-1].costsum;
//		cout<<"try:"<<score<<" "<<mincost<<endl;
		set<int> used[3];
		for(int q=0;q<score;q++){
			if(cost[q].score==1){
				used[1].insert( cost[q].probid );
			} else {
				if(used[1].count( cost[q].probid )==0){
					used[2].insert( cost[q].probid );
				} else {
					used[1].erase( cost[q].probid );
				}
			}
		}
		for(int q=score;q<n*2;q++){
//			cout<<" try:"<<q;
			if(cost[q-score].score==1){
				if(used[1].count( cost[q-score].probid )==0){
					used[2].insert( cost[q-score].probid );
				} else {
					used[1].erase( cost[q-score].probid );
				}
			} else {
				used[1].erase( cost[q-score].probid );
			}
			if(cost[q].score==1){
				used[1].insert( cost[q].probid );
			} else {
				if(used[1].count( cost[q].probid )==0){
					used[2].insert( cost[q].probid );
				} else {
					used[1].erase( cost[q].probid );
				}
			}
//			used[ cost[q-score].score ].erase(cost[q-score].probid);
//			used[ cost[q].score ].insert(cost[q].probid);
//			vector<int> diff;
//			set_difference(used[2].begin(),used[2].end(),used[1].begin(),used[1].end(),inserter(diff,diff.begin()));
//			if(diff.size()==0){
				long long tempcost=cost[q].costsum-cost[q-score].costsum;
//				cout<<" "<<tempcost;
			if(used[2].size()==0){
				if(tempcost<mincost)mincost=tempcost;
			}
//			cout<<endl;
		}
//		cout<<"mincost:"<<mincost<<endl;
		if(mincost>t){
			sea_r=score-1;
		}else {
			sea_l=score;
		}
	}
	cout<<sea_l<<endl;
}
