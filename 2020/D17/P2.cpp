#include <bits/stdc++.h>

using namespace std;

int main() {
	set<tuple<int,int,int,int>> active;
	string line;
	int i = 0;
	while(getline(cin, line)) {
		for(int j = 0; j < line.size(); j++) {
			if(line[j] == '#') {
				active.insert(make_tuple(i, j, 0, 0));
			}
		}
		i++;
	}
	for(int i = 0; i < 6; i++) {
		map<tuple<int,int,int,int>, int> adj;
		for(auto t : active) {
			for(int x = get<0>(t)-1; x <= get<0>(t)+1; x++) {
				for(int y = get<1>(t)-1; y <= get<1>(t)+1; y++) {
					for(int z = get<2>(t)-1; z <= get<2>(t)+1; z++) {
						for(int w = get<3>(t)-1; w <= get<3>(t)+1; w++) {
							if(x == get<0>(t) &&
								y == get<1>(t) &&
								z == get<2>(t) &&
								w == get<3>(t))
								continue;
							adj[make_tuple(x, y, z, w)]++;
						}
					}
				}
			}
		}
		set<tuple<int,int,int,int>> newActive;
		for(auto p : adj) {
			if(p.second == 3 || (p.second == 2 && active.find(p.first) != active.end())) {
				newActive.insert(p.first);
			}
		}
		active = newActive;
	}
	cout << active.size() << endl;
}
