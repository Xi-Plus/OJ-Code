// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long RAND(long long a,long long b){
	long long m=b-a+1;
	int d=int(log2(m-1))+1;
	long long res=m+1;
	while(res>=m){
		res=0;
		for(int q=0;q<d;q++){
			res<<=1;
			res|=rand()%2;
		}
	}
	return res+a;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	srand(time(NULL));
	for(int q=0;q<100;q++){
		cout<<RAND(2147483647,2147483649)<<endl;
	}
}
