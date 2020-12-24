#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll pow2(int p) {
	ll x = 1;
	for(int i = 0; i < p; i++) {
		x*=2;
	}
	return x;
}

int main() {
	string s;
	ll mask1;
	ll maskX0;
	ll maskX1;
	ll xCount;
	vector<ll> xbits;
	map<ll, ll> mem;
	while(cin >> s) {
		if(s == "mask") {
			string mask; cin >> mask;
			mask1 = 0;
			xCount = 1;
			xbits = vector<ll>();
			ll bit = 1;
			for(int i = mask.size()-1; i >= 0; i--, bit*=2) {
				if(mask[i] == 'X') {
					xCount*=2;
					xbits.push_back(mask.size() - i - 1);
				} else if(mask[i] == '1') {
					mask1 += bit;
				}
			}
		} else {
			ll idx, val; cin >> idx >> val;
			for(int i = 0; i < xCount; i++) {
				maskX0 = 0xffffffffffffffff;
				maskX1 = 0;
				for(int j = 0; j < xbits.size(); j++) {
					if(i & (1<<j)) {
						maskX1 += pow2(xbits[j]);
					} else {
						maskX0 -= pow2(xbits[j]);
					}
				}
				ll addr = idx;
				addr |= mask1;
				addr &= maskX0;
				addr |= maskX1;
				mem[addr] = val;
			}
		}
	}
	ll sum = 0;
	for(auto p : mem) {
		sum += p.second;
	}
	cout << sum << endl;
}
