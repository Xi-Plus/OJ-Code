#include <bits/stdc++.h>
using namespace std;
int roman2int(char c){
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
int main(){
	string s1,s2;
	while(cin>>s1){
		if(s1=="#")break;
		cin>>s2;
		int l1=s1.size(),l2=s2.size();
		int v1[l1+1],v2[l2+1];
		v1[l1]=0;
		v2[l2]=0;
		for(int q=0;q<l1;q++)v1[q]=roman2int(s1[q]);
		for(int q=0;q<l2;q++)v2[q]=roman2int(s2[q]);
		int n1=0,n2=0;
		for(int q=0;q<l1;q++){
			if(v1[q]<v1[q+1]){
				n1+=v1[q+1]-v1[q];
				q++;
			}
			else n1+=v1[q];
		}
		for(int q=0;q<l2;q++){
			if(v2[q]<v2[q+1]){
				n2+=v2[q+1]-v2[q];
				q++;
			}
			else n2+=v2[q];
		}
		int n=abs(n1-n2);
		
		if(n==0)cout<<"ZERO";
		else {
			int	a=n/1000;n%=1000;
			int b=n/100;n%=100;
			int c=n/10;n%=10;
			int d=n;
			
			for(int q=0;q<a;q++)cout<<"M";
			
			if(b==4)cout<<"CD";
			else if(b==9)cout<<"CM";
			else {
				if(b>=5)cout<<"D";
				for(int q=0;q<b%5;q++)cout<<"C";
			}
			
			if(c==4)cout<<"XL";
			else if(c==9)cout<<"XC";
			else {
				if(c>=5)cout<<"L";
				for(int q=0;q<c%5;q++)cout<<"X";
			}
			
			if(d==4)cout<<"IV";
			else if(d==9)cout<<"IX";
			else {
				if(d>=5)cout<<"V";
				for(int q=0;q<d%5;q++)cout<<"I";
			}	
		}
		cout<<endl;
	}
}
