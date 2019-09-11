#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c[105][105];
	memset(c, ' ', sizeof(c));
	int row=0, col=0;
	string s;
	while(getline(cin, s)){
		col=max(col, (int)s.size());
		for(int q=0; q<s.size(); q++){
			c[row][q]=s[q];
		}
		row++;
	}
	for(int q=0; q<col; q++){
		for(int w=row-1; w>=0; w--){
			cout<<c[w][q];
		}
		cout<<endl;
	}
}
