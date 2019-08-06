#include <bits/stdc++.h>
using namespace std;

double add(double a, double b){
	return a+b;
}
double sub(double a, double b){
	return a-b;
}
double mul(double a, double b){
	return a*b;
}
double div(double a, double b){
	return a/b;
}
typedef double (*ScriptFunction)(double, double);

int main(){
	map<char, ScriptFunction> func;
	func['+'] = add;
	func['-'] = sub;
	func['*'] = mul;
	func['/'] = div;
	
    double a,b;
    char c;
    cin>>a>>c>>b;
    cout<<fixed<<setprecision(4);
    if(c == '/' && b == 0) cout<<"ERROR"<<endl;
    else cout<<a<<" "<<c<<" "<<b<<" = "<<func[c](a, b)<<endl;
}
