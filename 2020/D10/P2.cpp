#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> arr;
	arr.push_back(0);
	int a;
	while(cin >> a) {
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	arr.push_back(arr[arr.size()-1] + 3);
	vector<long long> counts(arr.size(), 0);
	counts[0] = 1;
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] - arr[i-1] <= 3) {
			counts[i] += counts[i-1];
		}
		if(i > 1 && arr[i] - arr[i-2] <= 3) {
			counts[i] += counts[i-2];
		}
		if(i > 2 && arr[i] - arr[i-3] <= 3) {
			counts[i] += counts[i-3];
		}
	}
	cout << counts[counts.size()-1] << endl;
}
