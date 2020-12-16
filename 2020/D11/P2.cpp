#include <bits/stdc++.h>

using namespace std;

bool isValid(const vector<string> &grid, int i, int j) {
	return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

bool seatVisible(const vector<string> &grid, int i, int j, int dx, int dy) {
	i += dy;
	j += dx;
	while(isValid(grid, i, j)) {
		if(grid[i][j] == '#') return true;
		if(grid[i][j] == 'L') return false;
		i += dy;
		j += dx;
	}
	return false;
}

int adj(const vector<string> &grid, int i, int j) {
	int ret = 0;
	if(seatVisible(grid, i, j, 1, 0)) ret++;
	if(seatVisible(grid, i, j, 1, -1)) ret++;
	if(seatVisible(grid, i, j, 1, 1)) ret++;
	if(seatVisible(grid, i, j, 0, -1)) ret++;
	if(seatVisible(grid, i, j, 0, 1)) ret++;
	if(seatVisible(grid, i, j, -1, 0)) ret++;
	if(seatVisible(grid, i, j, -1, -1)) ret++;
	if(seatVisible(grid, i, j, -1, 1)) ret++;
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
				if(adj(grid, i, j) >= 5) {
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
