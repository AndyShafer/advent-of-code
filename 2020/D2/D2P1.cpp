#include <bits/stdc++.h>

using namespace std;

int main() {
	int mn, mx;
	string ch, pass;
	int valid = 0;
	while(cin >> mn >> mx >> ch >> pass) {
		int c = 0;
		for(char p : pass) {
			if(p == ch[0]) c++;
		}
		if(c >= mn && c <= mx) valid++;
	}
	cout << valid << endl;
}
