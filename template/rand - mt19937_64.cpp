// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	mt19937_64 rng;
	rng.seed(time(NULL));
	uniform_int_distribution<unsigned long long> dis;
	cout<<dis(rng)<<endl;
	
	mt19937 mt(time(NULL));
	cout<<mt()<<endl;
}

