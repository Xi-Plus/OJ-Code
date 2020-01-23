#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Record{
	string name;
	int a, b, rank;
};
bool cmp(Record r1, Record r2){
	if(r1.a==r2.a){
		if(r1.b==r2.b){
			if(r1.name.size()==r2.name.size()){
				return r1.name<r2.name;
			}
			return r1.name.size()<r2.name.size();
		}
		return r1.b<r2.b;
	}
	return r1.a>r2.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, s2;
	int n;
	bool firstcase=true;
	while(cin>>n){
		if(!firstcase){
			printf("\n");
		}
		firstcase = false;
		cin.get();
		vector<Record> record;
		for(int q=0; q<n; q++){
			getline(cin, s);
			int i=s.size()-1;
			int a=0, b=0, k=1;
			for(;s[i]!=' '; i--){
				b+=(s[i]-'0')*k;
				k*=10;
			}
			i--;
			k=1;
			for(;s[i]!=' '; i--){
				a+=(s[i]-'0')*k;
				k*=10;
			}
			s2=s.substr(0, i);
			record.push_back({s2, a, b, 0});
		}
		sort(record.begin(), record.end(), cmp);
		record[0].rank=1;
		int maxrank=1;
		int maxnamesize = record[0].name.size();
		int maxa=record[0].a, maxb=record[0].b;
		for(int q=1; q<n; q++){
			if(record[q].a==record[q-1].a&&record[q].b==record[q-1].b){
				record[q].rank=record[q-1].rank;
			}else{
				record[q].rank=q+1;
			}
			maxrank=max(maxrank, record[q].rank);
			maxnamesize=max(maxnamesize, (int)record[q].name.size());
			maxa=max(maxa, record[q].a);
			maxb=max(maxb, record[q].b);
		}
		int rankdig = ceil(log10(maxrank+1));
		int adig = ceil(log10(maxa+1));
		int bdig = ceil(log10(maxb+1));
		for(auto r:record){
			printf("Rank %0*d: %*s %0*d %0*d\n", rankdig, r.rank, maxnamesize, r.name.c_str(), adig, r.a, bdig, r.b);
		}
	}
}

