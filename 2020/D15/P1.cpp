#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> nums = { 6, 3, 15, 13, 1, 0 };
	map<int,int> lastSpoken;
	for(int i = 0; i < nums.size(); i++) {
		lastSpoken[nums[i]] = i;
	}
	for(int i = nums.size(); i < 2020; i++) {
		if(lastSpoken.find(nums[i-1]) == lastSpoken.end()) {
			nums.push_back(0);
		} else {
			nums.push_back(i-1-lastSpoken[nums[i-1]]);
		}
		lastSpoken[nums[i-1]] = i-1;
	}
	cout << nums[2019] << endl;
}
