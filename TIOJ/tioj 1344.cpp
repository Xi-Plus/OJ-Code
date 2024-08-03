// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int c2n(char c){
	if(c=='M')return 1;
	else if(c=='B')return 2;
	else return 4;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,i;
	char c;
	while(cin>>n){
		int la1=0,la2=0,lb1=0,lb2=0,ans=0;
		while(n--){
			cin>>c;
			i=c2n(c);
			int sa=i|la1|la2;
			sa=(sa&1)+((sa&2)>>1)+((sa&4)>>2);
			int sb=i|lb1|lb2;
			sb=(sb&1)+((sb&2)>>1)+((sb&4)>>2);
//			cout<<"input "<<i<<" "<<sa<<" "<<sb<<" "<<endl;
			int put;
			if(sa>sb)put=1;
			else if(sa<sb)put=2;
			else {
				if(i==la2){
					if(i==lb2){
						if(i==la1)put=2;
						else put=1;
					}else {
						put=2;
					}
				}else {
					put=1;
				}
			}
			if(put==1){
//				cout<<"put a" <<endl;
				ans+=sa;
				la1=la2;
				la2=i;
			}else {
//				cout<<"put b" <<endl;
				ans+=sb;
				lb1=lb2;
				lb2=i;
			}
		}
		cout<<ans<<endl;
	}
}
