// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s;
	while(getline(cin,s)){
		string a="";
		int n=0;
		for(int q=0;q<s.size();q++){
			if((s[q]<='Z'&&s[q]>='A')||(s[q]<='z'&&s[q]>='a')){
				int k=s[q];k=k%3+48;
				char c=k;
				a+=c;
				n++;
			}
			if(n==14)break;
		}
		cout<<a[0]<<a[1]<<a[2]<<a[3]<<"/"<<a[4]<<a[5]<<"/"<<a[6]<<a[7]<<" "<<a[8]<<a[9]<<":"<<a[10]<<a[11]<<":"<<a[12]<<a[13]<<endl;
	}
}
