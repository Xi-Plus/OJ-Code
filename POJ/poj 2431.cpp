#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;
pair<int,int> stop[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a, b;
	for(int q=0; q<n; q++) {
		cin>>stop[q].first>>stop[q].second;
	}
	stop[n] = {0, 0};
	sort(stop, stop+n+1);
	int l, p;
	cin>>l>>p;
	int ans=0;
	priority_queue<int> pq;
	for(int q=n; q>=0; q--) {
		while(p < l-stop[q].first && !pq.empty()) {
			ans++;
			p += pq.top();
			pq.pop();
		}
		if(p < l-stop[q].first) {
			cout<<-1<<endl;
			return 0;
		}
		pq.push(stop[q].second);
	}
	cout<<ans<<endl;
}
