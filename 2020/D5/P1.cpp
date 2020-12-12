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
	int highestId = 0;
	while(cin >> s) {
		int r = getRow(s);
		int c = getCol(s);
		highestId = max(highestId, r*8+c);
	}
	cout << highestId << endl;
}
