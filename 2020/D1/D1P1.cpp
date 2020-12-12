#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> nums;
	int a;
	while(cin >> a) {
		if(nums.find(2020-a) != nums.end()) {
			cout << a * (2020-a) << endl;
		}
		nums.insert(a);
	}
}
