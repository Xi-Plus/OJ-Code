#include <bits/stdc++.h>
using namespace std;
int char2int(char c){
	switch(c){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
	}
	return 0;
}
int roman2num(string s){
	int l=s.size();
	int v[l+1];
	v[l]=0;
	for(int q=0;q<l;q++)v[q]=char2int(s[q]);
	int n=0;
	for(int q=0;q<l;q++){
		if(v[q]<v[q+1]){
			n+=v[q+1]-v[q];
			q++;
		}
		else n+=v[q];
	}
	return n;
}
string num2roman(int n){
	string temp="";
	int	a=n/1000;n%=1000;
	int b=n/100;n%=100;
	int c=n/10;n%=10;
	int d=n;
	
	for(int q=0;q<a;q++)temp+="M";
	
	if(b==4)temp+="CD";
	else if(b==9)temp+="CM";
	else {
		if(b>=5)temp+="D";
		for(int q=0;q<b%5;q++)temp+="C";
	}
	
	if(c==4)temp+="XL";
	else if(c==9)temp+="XC";
	else {
		if(c>=5)temp+="L";
		for(int q=0;q<c%5;q++)temp+="X";
	}
	
	if(d==4)temp+="IV";
	else if(d==9)temp+="IX";
	else {
		if(d>=5)temp+="V";
		for(int q=0;q<d%5;q++)temp+="I";
	}
	return temp;
}
int main(){
	int t;
	int k;
	int n;
	string s;
	cin>>t;
	while(t--){
		cin>>k;
		if(k==1){
			cin>>s;
			cout<<roman2num(s)<<endl;
		}else {
			cin>>n;
			cout<<num2roman(n)<<endl;
		}
	}
}
