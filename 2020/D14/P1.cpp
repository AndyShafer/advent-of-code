#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main() {
	string s;
	ll mask0;
	ll mask1;
	map<ll, ll> mem;
	while(cin >> s) {
		if(s == "mask") {
			string mask; cin >> mask;
			mask0 = 0xffffffffffffffff;
			mask1 = 0;
			ll bit = 1;
			for(int i = mask.size()-1; i >= 0; i--, bit*=2) {
				if(mask[i] == '0') {
					mask0 -= bit;
				} else if(mask[i] == '1') {
					mask1 += bit;
				}
			}
		} else {
			ll idx, val; cin >> idx >> val;
			val &= mask0;
			val |= mask1;
			mem[idx] = val;
		}
	}
	ll sum = 0;
	for(auto p : mem) {
		sum += p.second;
	}
	cout << sum << endl;
}
