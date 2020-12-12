#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> nums;
	vector<int> arr;
	int a;
	while(cin >> a) {
		nums.insert(a);
		arr.push_back(a);
	}
	for(int i = 0; i < arr.size(); i++) {
		for(int j = i+1; j < arr.size(); j++) {
			if(nums.find(2020-arr[i]-arr[j]) != nums.end()) {
				cout << arr[i]*arr[j]*(2020-arr[i]-arr[j]) << endl;
			}
		}
	}
}
