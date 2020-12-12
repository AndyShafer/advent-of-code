#include <bits/stdc++.h>

using namespace std;

typedef pair<string,string> bag;

void dfs(map<bag, vector<bag>> &invMap, bag b, set<bag> &visited) {
	for(bag x : invMap[b]) {
		if(visited.find(x) == visited.end()) {
			visited.insert(x);
			dfs(invMap, x, visited);
		}
	}
}

int main() {
	map<bag, vector<pair<bag, int>>> bagMap;
	map<bag, vector<bag>> invMap;
	bag b;
	while(cin >> b.first >> b.second) {
		vector<pair<bag, int>> contains;
		int n;
		bag x;
		string y;
		do {
			cin >> n;
			if(n == 0) {
				cin >> y;
				break;
			}
			cin >> x.first >> x.second >> y;
			contains.push_back(make_pair(x, n));
			invMap[x].push_back(b);
		} while(y != "end");
		bagMap[b] = contains;
	}
	bag sg = make_pair("shiny", "gold");
	set<bag> visited;
	visited.insert(sg);
	dfs(invMap, sg, visited);
	cout << visited.size()-1 << endl;
}
