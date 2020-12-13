#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	vector<ll> arr;
	ll n;
	while(cin >> n) {
		arr.push_back(n);
	}
	for(int i = 25; i < arr.size(); i++) {
		set<ll> vals;
		for(int j = i-25; j < i; j++) {
			vals.insert(arr[j]);
		}
		bool valid = false;
		for(ll v : vals) {
			if(vals.find(arr[i]-v) != vals.end()) {
				valid = true;
				break;
			}
		}
		if(!valid) {
			cout << arr[i] << endl;
		}
	}
}
