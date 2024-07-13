// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
//	ios::sync_with_stdio(false); cin.tie(0);
	int n, a;
	while(cin>>n&&n) {
		while(cin>>a&&a) {
			stack<int> s, t;
			for(int q=n; q>=1; q--) {
				t.push(q);
			}
			bool ans=true;
			for(int q=0; q<n; q++) {
				if(q) {
					cin>>a;
				}
				if(!s.empty()&&s.top()==a) {
					s.pop();
				}
				else {
					while(!t.empty()&&t.top()!=a) {
						s.push(t.top());
						t.pop();
					}
					if(t.empty()) {
						ans=false;
					}else{
						t.pop();
					}
				}
			}
			if (ans) {
				cout<<"Yes"<<endl;
			} else {
				cout<<"No"<<endl;
			}
		}
		cout<<endl;
	}
}
