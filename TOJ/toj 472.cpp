#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int lowbit(int n){
	return n&-n;
}
struct BIT{
	long long v[1000005];
	void add(int n){
		for(;n<1000005;n+=lowbit(n)){
			v[n]++;
		}
	}
	long long sum(int n){
		long long a=0;
		for(;n>0;n-=lowbit(n)){
			a+=v[n];
		}
		return a;
	}
}bit;
struct BIT2{
	long long v[1000005];
	void add(int n, int d){
		for(;n>0;n-=lowbit(n)){
			v[n]+=d;
		}
	}
	long long sum(int n){
		long long a=0;
		for(;n<1000005;n+=lowbit(n)){
			a+=v[n];
		}
		return a;
	}
}bit2;
int v[1000005];
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin>>n;
	for(int q=0; q<n; q++){
		cin>>v[q];
	}
	for(int q=n-1; q>=0; q--){
		bit2.add(v[q], 1);
	}
	long long a=0;
	for(int q=0; q<n; q++){
		bit.add(v[q]);
		a+=bit.sum(v[q]-1)*bit2.sum(v[q]+1);
		bit2.add(v[q], -1);
	}
	cout<<a<<endl;
}

