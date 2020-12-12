#include <bits/stdc++.h>

using namespace std;

long long slope(vector<string>& trees, int r, int d) {
	long long count = 0;
	for(int i = 0; i < trees.size(); i+=d) {
		if(trees[i][((i/d)*r) % trees[i].size()] == '#')
			count++;
	}
	return count;
}

int main() {
	string line;
	vector<string> trees;
	while(getline(cin, line)) {
		trees.push_back(line);
	}
	cout << slope(trees, 1, 1) * slope(trees, 3, 1) * slope(trees, 5, 1) * slope(trees, 7, 1) * slope(trees, 1, 2) << endl;
}
