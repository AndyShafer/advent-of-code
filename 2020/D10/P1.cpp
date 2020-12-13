#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> arr;
	int a;
	while(cin >> a) {
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int jolt = 0;
	int ones = 0;
	int threes = 0;
	for(int x : arr) {
		if(x - jolt == 1) ones++;
		if(x - jolt == 3) threes++;
		jolt = x;
	}
	threes++;
	cout << ones * threes << endl;
}
