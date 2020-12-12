#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	vector<string> trees;
	while(getline(cin, line)) {
		trees.push_back(line);
	}
	int count = 0;
	for(int i = 0; i < trees.size(); i++) {
		if(trees[i][(i*3) % trees[i].size()] == '#')
			count++;
	}
	cout << count << endl;
}
