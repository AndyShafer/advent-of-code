#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> ranges;

bool isValid(int val) {
	for(pair<int,int> p : ranges) {
		if(p.first <= val && p.second >= val) return true;
	}
	return false;
}

int main() {
	string s;
	string skip;
	cin >> s;
	int fields = 0;
	while(s != "your_ticket") {
		fields++;
		int a, b, c, d;
		cin >> a >> b >> skip >> c >> d;
		ranges.push_back(make_pair(a, b));
		ranges.push_back(make_pair(c, d));
		cin >> s;
	}
	
	int invalid = 0;
	int val;
	for(int i = 0; i < fields; i++) {
		cin >> val;
		if(!isValid(val)) invalid += val;	
	}

	cin >> skip;
	while(cin >> val) {
		if(!isValid(val)) invalid += val;	
	}

	cout << invalid << endl;
}
