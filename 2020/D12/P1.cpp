#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int n;
	int x = 0;
	int y = 0;
	int dir = 0; // East
	while(cin >> s >> n) {
		switch(s[0]) {
			case 'N':
				y += n;
				break;
			case 'S':
				y -= n;
				break;
			case 'E':
				x += n;
				break;
			case 'W':
				x -= n;
				break;
			case 'F':
				switch(dir) {
					case 0:
						x += n;
						break;
					case 1:
						y -= n;
						break;
					case 2:
						x -= n;
						break;
					case 3:
						y += n;
						break;
				}
				break;
			case 'L':
				dir += (4-n/90);
				dir %= 4;
				break;
			case 'R':
				dir += n/90;
				dir %= 4;
				break;
		}
	}
	cout << abs(x) + abs(y) << endl;
}
