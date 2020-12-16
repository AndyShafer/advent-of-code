#include <bits/stdc++.h>

using namespace std;

int adj(const vector<string> &grid, int i, int j) {
	int ret = 0;
	if(i > 0) {
		if(grid[i-1][j] == '#') ret++;
		if(j > 0 && grid[i-1][j-1] == '#') ret++;
		if(j < grid[0].size()-1 && grid[i-1][j+1] == '#') ret++;
	}
	if(j > 0 && grid[i][j-1] == '#') ret++;
	if(i < grid.size()-1) {
		if(grid[i+1][j] == '#') ret++;
		if(j > 0 && grid[i+1][j-1] == '#') ret++;
		if(j < grid[0].size()-1 && grid[i+1][j+1] == '#') ret++;
	}
	if(j < grid[0].size()-1 && grid[i][j+1] == '#') ret++;
	return ret;
}
vector<string> step(const vector<string> &grid) {
	vector<string> ret = grid;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 'L') {
				if(adj(grid, i, j) == 0) {
					ret[i][j] = '#';
				}
			} else if(grid[i][j] == '#') {
				if(adj(grid, i, j) >= 4) {
					ret[i][j] = 'L';
				}
			}
		}
	}
	return ret;
}

int count(const vector<string> &grid) {
	int ret = 0;
	for(string s : grid) {
		for(char c : s) {
			if(c == '#') ret++;
		}
	}
	return ret;
}

void printg(const vector<string> &grid) {
	for(int i = 0; i < grid.size() && i < 20; i++) {
		for(int j = 0; j < grid[i].size() && j < 20; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<string> grid;
	string s;
	while(getline(cin, s)) {
		grid.push_back(s);
	}
	vector<string> newGrid = step(grid);
	while(grid != newGrid) {
		//printg(grid);
		grid = newGrid;
		newGrid = step(grid);
	}
	cout << count(grid) << endl;
}
