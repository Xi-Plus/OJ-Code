#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--){
		char s[11];
		scanf("%s", s);
		int sz = strlen(s);
		sort(s, s+sz);
		do {
			cout<<s<<endl;
		} while(next_permutation(s, s+sz));
		cout<<endl;
	}
}
