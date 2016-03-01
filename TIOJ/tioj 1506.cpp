// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Multiple{
	double x,y;
};
Multiple Cramer(double a,double b,double c,double d,double e,double f){
	// ax+by=e
	// cx+dy=f
	// https://zh.wikipedia.org/wiki/%E5%85%8B%E8%90%8A%E5%A7%86%E6%B3%95%E5%89%87#.E4.BE.8B.E5.AD.90
	if(a*d==b*c)return {NAN,NAN};
	return {(e*d-b*f)/(a*d-b*c),(a*f-e*c)/(a*d-b*c)};
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	double a,b,c,d;
	while(cin>>a>>b>>c>>d){
		Multiple t=Cramer(-a,1,-b,1,c,d);
		cout<<fixed<<setprecision(2)<<t.x<<endl<<t.y<<endl;
	}
}

