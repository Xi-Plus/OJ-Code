// By KRT girl xiplus
#include <iostream>
#define endl '\n'
using namespace std;
int vn[]={1,1,4,4,2,1,1,4,4,2};
int v[][4]={
	{0},
	{1},
	{6,2,4,8},
	{1,3,9,7},
	{6,4},
	{5},
	{6},
	{1,7,9,3},
	{6,8,4,2},
	{1,9}
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s1,s2;
	int n,m;
	while(cin>>s1>>s2,s1!="0"||s2!="0"){
		s2="0"+s2;
		n=(s1[s1.size()-1]-'0');
		m=(s2[s2.size()-2]-'0')*10+(s2[s2.size()-1]-'0');
		if(n==0)cout<<0<<endl;
		else if(m==0)cout<<1<<endl;
		else cout<<v[n][m%vn[n]]<<endl;
	}
}
