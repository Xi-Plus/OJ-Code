#include <bits/stdc++.h>
#define asd(a;b;c){d} a;qqq:if(b){c;goto qqq}
using namespace std;
string replaceAll(string str, string from, string to) {
	size_t pos = 0;
	while ((pos = str.find(from, pos)) != string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
	return str;
}
int main() {
	asd(int i = 0; i < 10; i++) {
		cout << i << endl;
	}
	string str;
	cout << "#define fff for\n";
	cout << "#define www while\n";
	cout << "#define ddd do\n";
	while (getline(cin, str)) {
		str = replaceAll(str, "for", "fff");
		str = replaceAll(str, "while", "www");
		str = replaceAll(str, "do", "ddd");
		cout << str << endl;
	}
}
