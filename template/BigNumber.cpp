// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct BigNumber{
	const int BASE = 100000000;
	const int WIDTH = 8;
	vector<int> s;
	bool sign=0;

	operator long long(){
		long long num=0;
		int sz=s.size();
		for(int i=sz-1;i>=0;i--){
			num*=BASE;
			num+=s[i];
		}
		if(sign)return -num;
		else return num;
	}
	operator string(){
		string num="";
		int sz=s.size();
		for(int i=sz-1;i>=0;i--){
			num+=to_string(s[i]);
		}
		if(sign)return "-"+num;
		else return num;
	}

	BigNumber(long long num = 0) { *this = num; }
	BigNumber operator = (long long num) {
		s.clear();
		if(num<0){
			sign=1;
			num*=-1;
		}
		do {
			s.push_back(num % BASE);
			num /= BASE;
		} while(num>0);
		return *this;
	}
	BigNumber operator = (string str){
		s.clear();
		if(str[0]=='-'){
			sign=1;
			str.erase(0,1);
		}
		int x, len = (str.length()-1)/WIDTH +1;
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			stringstream(str.substr(start,end-start))>>x;
//			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	BigNumber plus(BigNumber a,BigNumber b){
		BigNumber c;
		c.sign=a.sign;
		c.s.clear();
		for(int i=0,g=0;;i++){
			if(g==0&&i>=s.size()&&i>=b.s.size()) break;
			int x=g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	BigNumber operator + (BigNumber b){
		if(sign^b.sign==0){
			return plus(*this,b);
		}
	}
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	BigNumber b1=-111111111111111;
	BigNumber b2;
	b2="-222222222222222222222222222222222222222222222";
	cout<<(string)b1<<endl;
	cout<<(string)b2<<endl;
	cout<<(string)(b1+b2)<<endl;
}
