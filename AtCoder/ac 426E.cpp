// By xiplus
// WA
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long double tsx, tsy, tgx, tgy, asx, asy, agx, agy;
long double tdis, adis;
long double tx, ty, ax, ay;
long double f(long double t) {
	if (t >= tdis) {
		tx = tgx;
		ty = tgy;
	} else {
		tx = tsx + (tgx - tsx) / tdis * t;
		ty = tsy + (tgy - tsy) / tdis * t;
	}
	if (t >= adis) {
		ax = agx;
		ay = agy;
	} else {
		ax = asx + (agx - asx) / adis * t;
		ay = asy + (agy - asy) / adis * t;
	}
	return pow(tx - ax, 2) + pow(ty - ay, 2);
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
		tdis = sqrt(pow(tsx - tgx, 2) + pow(tsy - tgy, 2));
		adis = sqrt(pow(asx - agx, 2) + pow(asy - agy, 2));
		long double l = 0, r = min(tdis, adis), ml, mr, ansl, ansr, ans1;
		for (int i = 0; i < 100; i++) {
			ml = (l * 2 + r) / 3;
			mr = (l + r * 2) / 3;
			ansl = f(ml);
			ansr = f(mr);
			if (ansl < ansr) {
				r = mr;
			} else {
				l = ml;
			}
			if (abs(l - r) < 1e-15 && abs(ansl - ansr) < 1e-15) {
				// cout << i << endl;
				break;
			}
		}
		ans1 = ansl;

		l = min(tdis, adis), r = max(tdis, adis);
		for (int i = 0; i < 100; i++) {
			ml = (l * 2 + r) / 3;
			mr = (l + r * 2) / 3;
			ansl = f(ml);
			ansr = f(mr);
			if (ansl < ansr) {
				r = mr;
			} else {
				l = ml;
			}
			if (abs(l - r) < 1e-15 && abs(ansl - ansr) < 1e-15) {
				// cout << i << endl;
				break;
			}
		}
		cout << fixed << setprecision(30) << sqrt(min(ans1, ansl)) << endl;
	}
}
