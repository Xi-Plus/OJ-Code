#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N;
	string s;
	cin>>T;
	while(T--){
		cin>>N;
		stack<set<int>> st;
		int setidcnt=0;
		map<set<int>, int> setid;
		while(N--){
			cin>>s;
			set<int> temp, temp1, temp2, temp3;
			switch(s[0]){
				case 'P':
					st.push(temp);
					break;
				case 'D':
					temp = st.top();
					st.push(temp);
					break;
				case 'U':
					temp1 = st.top();
					st.pop();
					temp2 = st.top();
					st.pop();
					for(auto t:temp2){
						temp1.insert(t);
					}
					st.push(temp1);
					break;
				case 'I':
					temp = st.top();
					st.pop();
					temp2 = st.top();
					st.pop();
					for(auto t:temp){
						if(temp2.count(t)){
							temp3.insert(t);
						}
					}
					st.push(temp3);
					break;
				case 'A':
					temp = st.top();
					st.pop();
					if(!setid.count(temp)){
						setid[temp] = setidcnt++;
					}
					st.top().insert(setid[temp]);
					break;
			}
			cout<<st.top().size()<<endl;
		}
		cout<<"***"<<endl;
	}
}
