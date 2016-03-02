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
int va[25]={0};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s1,s2;
	va[0]=0;
	for(int q=1;q<100;q++){
		va[q]=v[q%10][q%vn[q%10]];
		va[q]+=va[q-1];
		va[q]%=10;
	}
	int n,m;
	while(cin>>s1>>s2){
		s1="0"+s1;
		s2="0"+s2;
		n=(s1[s1.size()-2]-'0')*10+(s1[s1.size()-1]-'0');
		m=(s2[s2.size()-2]-'0')*10+(s2[s2.size()-1]-'0');
		cout<<va[n]+va[m]<<endl;
	}
}