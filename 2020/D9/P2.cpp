#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	vector<ll> arr;
	ll n;
	ll x;
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
			x = arr[i];
		}
	}
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] == x) continue;
		ll sum = 0;
		ll smallest = arr[i];
		ll largest = arr[i];
		for(int j = i; i < arr.size(); j++) {
			smallest = min(arr[j], smallest);
			largest = max(arr[j], largest);
			sum += arr[j];
			if(sum == x) {
				cout << smallest + largest << endl;
				return 0;
			}
			if(sum > x) {
				break;
			}
		}
	}
}
