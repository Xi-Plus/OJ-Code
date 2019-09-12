#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	string s;
	while(cin>>n, n){
		int a[]={1,2,3,6,5,4};//top,N,W,bot,S,E
		while(n--){
			cin>>s;
			switch(s[0]){
				case 'n':
					t=a[0];
					a[0]=a[4];
					a[4]=a[3];
					a[3]=a[1];
					a[1]=t;
					break;
				case 'e':
					t=a[0];
					a[0]=a[2];
					a[2]=a[3];
					a[3]=a[5];
					a[5]=t;
					break;
				case 's':
					t=a[0];
					a[0]=a[1];
					a[1]=a[3];
					a[3]=a[4];
					a[4]=t;
					break;
				case 'w':
					t=a[0];
					a[0]=a[5];
					a[5]=a[3];
					a[3]=a[2];
					a[2]=t;
					break;
			}
		}
		cout<<a[0]<<endl;
	}
}

