#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int s2n(string s){
	int ans=0;
	for(int q=0; q<s.size(); q++){
		ans*=2;
		ans+=s[q]-'0';
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n1, n2;
	cin>>T;
	string s1, s2;
	for(int t=1; t<=T; t++){
		cin>>s1>>s2;
		n1=s2n(s1);
		n2=s2n(s2);
		while((n1%=n2)&&(n2%=n1));
		if(n1+n2>1){
			cout<<"Pair #"<<t<<": All you need is love!"<<endl;
		}else{
			cout<<"Pair #"<<t<<": Love is not all you need!"<<endl;
		}
	}
}
