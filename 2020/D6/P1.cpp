#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	vector<set<char>> groups(1);
	while(getline(cin, line)) {
		if(line == "") {
			groups.push_back(set<char>());	
		} else {
			for(char c : line) {
				groups[groups.size()-1].insert(c);
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < groups.size(); i++) {
		sum += groups[i].size();
	}
	cout << sum << endl;
}
