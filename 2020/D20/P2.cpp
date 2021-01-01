#include <bits/stdc++.h>

using namespace std;

map<int, vector<string>> tiles;
map<string, vector<int>> edges;
map<int, int> outside;
vector<string> seaMonster = { "                  # ", "#    ##    ##    ###", " #  #  #  #  #  #   " };

#define UPPER 0
#define LEFT 1

vector<string> getEdges(vector<string> &block) {
	string e1, e2, e3, e4;
	for(int i = 0; i < 10; i++) {
		e1 += block[9-i][0];
		e2 += block[0][i];
		e3 += block[i][9];
		e4 += block[9][9-i];
	}
	vector<string> ret;
	ret.push_back(e1);
	ret.push_back(e2);
	ret.push_back(e3);
	ret.push_back(e4);
	reverse(e1.begin(), e1.end());
	reverse(e2.begin(), e2.end());
	reverse(e3.begin(), e3.end());
	reverse(e4.begin(), e4.end());
	ret.push_back(e1);
	ret.push_back(e2);
	ret.push_back(e3);
	ret.push_back(e4);
	return ret;
}

vector<string> rotate(vector<string> &grid) {
	vector<string> ret = grid;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid.size(); j++) {
			ret[i][j] = grid[j][grid.size()-i-1];
		}
	}
	return ret;
}

vector<string> transpose(vector<string> &grid) {
	vector<string> ret = grid;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid.size(); j++) {
			ret[i][j] = grid[j][i];
		}
	}
	return ret;
}

struct Tile {
	Tile() {
	}
	Tile(vector<string> p, int id) {
		vector<string> blockEdges = getEdges(p);
		pat = p;
		this->id = id;
		if(edges[blockEdges[0]].size() == 1 && edges[blockEdges[1]].size() == 1) {
			orientation = 0;
		}
		else if(edges[blockEdges[1]].size() == 1 && edges[blockEdges[2]].size() == 1) {
			orientation = 3;
		}
		else if(edges[blockEdges[2]].size() == 1 && edges[blockEdges[3]].size() == 1) {
			orientation = 2;
		}
		else if(edges[blockEdges[3]].size() == 1 && edges[blockEdges[0]].size() == 1) {
			orientation = 1;
		} else {
			orientation = -1;
		}
	}
	Tile(Tile tile, int r) {
		string match = tile.getEdge(r);
		if(edges[match][0] == tile.id)
			id = edges[match][1];
		else
			id = edges[match][0];
		pat = tiles[id];
		vector<string> block = tiles[id];
		vector<string> blockEdges = getEdges(block);
		if(match == blockEdges[0]) {
			if(r == UPPER) {
				orientation = 1;
			} else {
				orientation = 0;
			}
		}
		else if(match == blockEdges[1]) {
			if(r == UPPER) {
				orientation = 0;
			} else {
				orientation = 3;
			}
		}
		else if(match == blockEdges[2]) {
			if(r == UPPER) {
				orientation = 3;
			} else {
				orientation = 2;
			}
		}
		else if(match == blockEdges[3]) {
			if(r == UPPER) {
				orientation = 2;
			} else {
				orientation = 1;
			}
		}
		else if(match == blockEdges[4]) {
			if(r == UPPER) {
				orientation = 4;
			} else {
				orientation = 7;
			}
		}
		else if(match == blockEdges[5]) {
			if(r == UPPER) {
				orientation = 5;
			} else {
				orientation = 4;
			}
		}
		else if(match == blockEdges[6]) {
			if(r == UPPER) {
				orientation = 6;
			} else {
				orientation = 5;
			}
		}
		else if(match == blockEdges[7]) {
			if(r == UPPER) {
				orientation = 7;
			} else {
				orientation = 6;
			}
		} else {
			orientation  = -1;
		}
	}
	vector<string> getTransformedTile() {
		vector<string> x = vector<string>(10, "..........");
		vector<string> y = x;
		if(orientation >= 4) {
			for(int i = 0; i < pat.size(); i++) {
				for(int j = 0; j < pat.size(); j++) {
					x[i][j] = pat[j][i];
				}
			}
		} else {
			x = pat;
		}
		for(int i = 0; i < pat.size(); i++) {
			for(int j = 0; j < pat.size(); j++) {
				if(orientation % 4 == 0) {
					y[i][j] = x[i][j];
				} else if(orientation % 4 == 1) {
					y[j][9-i] = x[i][j];
				} else if(orientation % 4 == 2) {
					y[9-i][9-j] = x[i][j];
				} else {
					y[9-j][i] = x[i][j];
				}
			}
		}
		return y;
	}
	string getEdge(int r) {
		auto t = getTransformedTile();
		if(r == UPPER) {
			return t[9];
		} else {
			string s;
			for(int i = 0; i < 10; i++) {
				s += t[9-i][9];
			}
			return s;
		}
	}
	vector<string> transformedNoEdges() {
		auto x = getTransformedTile();
		vector<string> y = vector<string>(8);
		for(int i = 1; i < 9; i++) {
			for(int j = 1; j < 9; j++) {
				y[i-1][j-1] = x[i][j];
			}
		}
		return y;
	}
	vector<string> pat;
	int orientation;
	int id;
};

int main() {
	int id;
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
		vector<string> blockEdges = getEdges(tiles[id]);
		for(auto e : blockEdges) {
			edges[e].push_back(id);
		}
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
	int tl = -1;
	for(auto p : outside) {
		cout << p.first << ": " << p.second << endl;
		if(p.second == 4) {
			if(tl == -1) {
				tl = p.first;
			}
		}
	}
	cout << endl;

	int size = sqrt(tiles.size());
	vector<vector<Tile>> grid(size, vector<Tile>(size));
	grid[0][0] = Tile(tiles[tl], tl);
	for(int i = 0; i < size; i++) {
		if(i != 0) {
			grid[i][0] = Tile(grid[i-1][0], UPPER);
		}
		for(int j = 1; j < size; j++) {
			grid[i][j] = Tile(grid[i][j-1], LEFT);
		}
	}
	vector<string> fullGrid(size*8);
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			auto block = grid[i][j].transformedNoEdges();
			for(int k = 0; k < block.size(); k++) {
				for(int l = 0; l < block.size(); l++) {
					fullGrid[i*block.size()+k] += block[k][l];
				}
			}
		}
	}
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid.size(); j++) {
			cout << grid[i][j].id << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(string line : fullGrid) {
		cout << line << endl;
	}
	cout << endl;

	for(int i = 0; i < 8; i++) {
		if(i == 4)
			fullGrid = transpose(fullGrid);
		for(int j = 0; j < fullGrid.size() - seaMonster.size(); j++) {
			for(int k = 0; k < fullGrid.size() - seaMonster[0].size(); k++) {
				bool b = true;
				for(int l = 0; l < seaMonster.size(); l++) {
					for(int m = 0; m < seaMonster[0].size(); m++) {
						if(seaMonster[l][m] == '#' && fullGrid[j+l][k+m] != '#' && fullGrid[j+l][k+m] != 'O') {
							b = false;
							break;
						}
					}
					if(!b) break;
				}
				if(b) {
					for(int l = 0; l < seaMonster.size(); l++) {
						for(int m = 0; m < seaMonster[0].size(); m++) {
							if(seaMonster[l][m] == '#') {
								fullGrid[j+l][k+m] = 'O';
							}
						}
					}
				}
			}
		}
		fullGrid = rotate(fullGrid);
	}

	for(string line : fullGrid) {
		cout << line << endl;
	}
	cout << endl;

	int ans = 0;
	for(string line : fullGrid) {
		for(char ch : line) {
			if(ch == '#') {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
