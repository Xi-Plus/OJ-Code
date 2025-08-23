
// By xiplus
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#define endl '\n'
using namespace std;
string typenames[] = {"", "Mixed", "Proper", "Improper"};
void print(long long a, long long b) {
	// cout<<"("<<a<<"/"<<b<<") = ";
	if (a >= b) {
		cout << a / b;
		if (a % b > 0) {
			cout << " ";
		}
	}
	if (a % b > 0) {
		cout << a % b << "/" << b;
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	getline(cin, s);
	char op, c;
	int type1 = 0, type2 = 0;
	stringstream ss(s);
	string part;
	long long n, a1, a2, b1, b2;
	n = 0;
	ss >> part;
	if (part.find('/') == string::npos) {
		n = stol(part);
		ss >> part;
		type1 = 1;
	}
	stringstream sp(part);
	sp >> a1 >> c >> a2;
	if (type1 == 0) {
		if (a1 <= a2) {
			type1 = 2;
		} else {
			type1 = 3;
		}
	}
	a1 += n * a2;
	long long g = gcd(a1, a2);
	a1 /= g;
	a2 /= g;

	ss >> part;
	op = part[0];

	n = 0;
	ss >> part;
	if (part.find('/') == string::npos) {
		n = stol(part);
		ss >> part;
		type2 = 1;
	}
	sp = stringstream(part);
	sp >> b1 >> c >> b2;
	if (type2 == 0) {
		if (b1 <= b2) {
			type2 = 2;
		} else {
			type2 = 3;
		}
	}
	b1 += n * b2;
	g = gcd(b1, b2);
	b1 /= g;
	b2 /= g;
	cout << "A is a " << typenames[type1] << " Fraction." << endl;
	cout << "B is a " << typenames[type2] << " Fraction." << endl;
	print(a1, a2);
	cout << " " << op << " ";
	print(b1, b2);
	cout << endl;
	long long c1, c2;
	if (op == '+') {
		c2 = a2 * b2;
		c1 = a1 * b2 + b1 * a2;
	} else if (op == '*') {
		c2 = a2 * b2;
		c1 = a1 * b1;
	} else if (op == '/') {
		c2 = a2 * b1;
		c1 = a1 * b2;
	}
	g = gcd(c1, c2);
	c1 /= g;
	c2 /= g;
	print(c1, c2);
	cout << endl;
}
