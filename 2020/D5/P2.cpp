#include <bits/stdc++.h>

using namespace std;

int getRow(string s) {
	int r = 0;
	for(int i = 0; i < 7; i++) {
		r *= 2;
		if(s[i] == 'B') r+=1;
	}
	return r;
}

int getCol(string s) {
	int r = 0;
	for(int i = 7; i < 10; i++) {
		r *= 2;
		if(s[i] == 'R') r+=1;
	}
	return r;
}

int main() {
	string s;
	set<int> seats;
	while(cin >> s) {
		int r = getRow(s);
		int c = getCol(s);
		seats.insert(r*8+c);
	}
	for(int i = 0; i < 128*8; i++) {
		if(seats.find(i) == seats.end()) {
			cout << i << endl;
		}
	}
}
