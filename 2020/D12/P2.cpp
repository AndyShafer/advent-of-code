#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int n;
	int x = 0;
	int y = 0;
	int wx = 10;
	int wy = 1;
	int rot, tmp;
	while(cin >> s >> n) {
		switch(s[0]) {
			case 'N':
				wy += n;
				break;
			case 'S':
				wy -= n;
				break;
			case 'E':
				wx += n;
				break;
			case 'W':
				wx -= n;
				break;
			case 'F':
				x += wx*n;
				y += wy*n;
				break;
			case 'L':
				rot = (4-n/90);
				switch(rot) {
					case 0:
						break;
					case 1:
						tmp = wx;
						wx = wy;
						wy = -tmp;
						break;
					case 2:
						wx = -wx;
						wy = -wy;
						break;
					case 3:
						tmp = wx;
						wx = -wy;
						wy = tmp;
						break;
				}
				break;
			case 'R':
				rot = n/90;
				switch(rot) {
				case 0:
					break;
				case 1:
					tmp = wx;
					wx = wy;
					wy = -tmp;
					break;
				case 2:
					wx = -wx;
					wy = -wy;
					break;
				case 3:
					tmp = wx;
					wx = -wy;
					wy = tmp;
					break;
				}
				break;
		}
	}
	cout << abs(x) + abs(y) << endl;
}
