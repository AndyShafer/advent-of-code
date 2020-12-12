#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	set<char> all;
	for(char c = 'a'; c <= 'z'; c++) {
		all.insert(c);
	}
	vector<set<char>> groups(1, all);
	while(getline(cin, line)) {
		if(line == "") {
			groups.push_back(all);	
		} else {
			set<char> l;
			for(char c : line) {
				l.insert(c);
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(l.find(c) == l.end()) {
					groups[groups.size()-1].erase(c);
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < groups.size(); i++) {
		sum += groups[i].size();
	}
	cout << sum << endl;
}
