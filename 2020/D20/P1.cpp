#include <bits/stdc++.h>

using namespace std;

int main() {
	int id;
	map<int, vector<string>> tiles;
	map<string, vector<int>> edges;
	map<int, int> outside;
	string skip;
	while(cin >> id) {
		getline(cin, skip);
		tiles[id] = vector<string>(10);
		for(int i = 0; i < 10; i++) {
			getline(cin, tiles[id][i]);
		}
		string e1, e2, e3, e4;
		for(int i = 0; i < 10; i++) {
			e1 += tiles[id][9-i][0];
			e2 += tiles[id][0][i];
			e3 += tiles[id][i][9];
			e4 += tiles[id][9][9-i];
		}
		edges[e1].push_back(id);
		edges[e2].push_back(id);
		edges[e3].push_back(id);
		edges[e4].push_back(id);
		reverse(e1.begin(), e1.end());
		reverse(e2.begin(), e2.end());
		reverse(e3.begin(), e3.end());
		reverse(e4.begin(), e4.end());
		edges[e1].push_back(id);
		edges[e2].push_back(id);
		edges[e3].push_back(id);
		edges[e4].push_back(id);
	}
	for(auto p : edges) {
		if(p.second.size() == 1) {
			outside[p.second[0]]++;
		}
		cout << p.first << ": ";
		for(auto n : p.second) {
			cout << n << " ";
		}
		cout << endl;
	}
	cout << endl;
	long long ans = 1;
	for(auto p : outside) {
		cout << p.first << ": " << p.second << endl;
		if(p.second == 4) {
			ans *= p.first;
		}
	}
	cout << endl;
	cout << ans << endl;
}
