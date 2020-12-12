#include <bits/stdc++.h>

using namespace std;

typedef pair<string,string> bag;

long long dfs(map<bag, vector<pair<bag, int>>> &bagMap, bag b) {
	long long bags = 1;
	for(auto x : bagMap[b]) {
		bags += x.second * dfs(bagMap, x.first);
	}
	return bags;
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
	long long count = dfs(bagMap, sg);
	cout << count-1 << endl;
}
