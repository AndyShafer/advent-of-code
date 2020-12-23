#include <bits/stdc++.h>

using namespace std;

int main() {
	int ts; cin >> ts;
	vector<int> bus;
	int a;
	while(cin >> a) {
		bus.push_back(a);
	}
	int b = -1, m = 0x3fffffff;
	for(int B : bus) {
		int wait = ts%B == 0 ? 0 : B - (ts % B);
		if(wait < m) {
			m = wait;
			b = B;
		}
	}
	cout << b*m << endl;
}
