#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long cnt[10000005];
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	for(int q=2; q<10000005; q++){
		for(int w=q; w<10000005; w+=q){
			cnt[w]++;
		}
	}
	for(int q=1; q<10000005; q++){
		cnt[q] += cnt[q-1]+1;
	}
	map<char, int> number;
	pair<string, int> temp[]={
		{"fprFJT",0},
		{"bgzEG",1},
		{"hinULO",2},
		{"lquBC",3},
		{"coMPR",4},
		{"ajVKsX",5},
		{"dkDS",6},
		{"ytINZ",7},
		{"mvHQY",8},
		{"ewxAW",9},
	};
	for(auto t:temp){
		for(char c:t.first){
			number[c]=t.second;
//			cout<<c<<t.second<<endl;
		}
	}
	string s;
	while(getline(cin, s)){
		int p=0, q=0;
		int k=1;
		for(char c:s){
			if('0'<=c&&c<='9'){
				p+=(c-'0')*k;
				k*=10;
			}else if('a'<=c&&c<='z'){
				q*=10;
				q+=number[c];
			}else if('A'<=c&&c<='Z'){
				q*=10;
				q+=number[c];
			}
		}
//		cout<<p<<" "<<q<<endl;
		if(p>q){
			swap(p, q);
		}
		cout<<cnt[q]-cnt[p-1]<<endl;
	}
}

