#include <bits/stdc++.h>

using namespace std;

int main() {
	int mn, mx;
	string ch, pass;
	int valid = 0;
	while(cin >> mn >> mx >> ch >> pass) {
		if((pass[mn-1] == ch[0]) != (pass[mx-1] == ch[0])) valid++;
	}
	cout << valid << endl;
}
