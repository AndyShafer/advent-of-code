#include <bits/stdc++.h>

using namespace std;

map<string, vector<pair<int,int>>> ranges;
map<string, vector<bool>> colValid;
map<int, string> known;

bool isValid(int val) {
	for(auto rule : ranges) {
		for(pair<int,int> p : rule.second) {
			if(p.first <= val && p.second >= val) return true;
		}
	}
	return false;
}

bool isValid(int val, string &field) {
	for(pair<int,int> p : ranges[field]) {
		if(p.first <= val && p.second >= val) return true;
	}
	return false;
}

bool go(const vector<vector<int>> &vals, set<string> &fields, vector<string> &cols) {
	if(fields.size() == 0) return true;
	if(known[cols.size()] != "") {
		string k = known[cols.size()];
		fields.erase(k);
		cols.push_back(k);

		if(go(vals, fields, cols)) {
			return true;
		} else {
			if(k == "")
				cout << "!" << endl;
			fields.insert(k);
			cols.pop_back();
			return false;
		}
	}
	set<string> fieldsCpy = fields;
	for(string s : fieldsCpy) {
		if(colValid[s][cols.size()]) {
			fields.erase(s);
			cols.push_back(s);

			if(go(vals, fields, cols)) {
				return true;
			} else {
				if(s == "") cout << "?" << endl;
				cols.pop_back();
				fields.insert(s);
			}
		}
	}
	return false;
}

int main() {
	string s;
	string skip;
	cin >> s;
	set<string> fields;
	while(s != "your_ticket") {
		fields.insert(s);
		int a, b, c, d;
		cin >> a >> b >> skip >> c >> d;
		ranges[s].push_back(make_pair(a, b));
		ranges[s].push_back(make_pair(c, d));
		cin >> s;
	}
	
	vector<vector<int>> vals(1, vector<int>(fields.size()));
	int val;
	for(int i = 0; i < fields.size(); i++) {
		cin >> vals[0][i];
	}

	cin >> skip;
	while(cin >> val) {
		vector<int> row(fields.size());
		row[0] = val;
		for(int i = 1; i < fields.size(); i++) {
			cin >> row[i];
		}
		bool valid = true;
		for(int i = 0; i < fields.size(); i++) {
			if(!isValid(row[i])) {
				valid = false;	
				break;
			}
		}
		if(valid) {
			vals.push_back(row);
		}
	}

	vector<string> cols;
	set<pair<int, string>> fieldSet;
	for(string field : fields) {
		cout << field << ": ";
		colValid[field] = vector<bool>(fields.size());
		//int count = 0;
		for(int i = 0; i < fields.size(); i++) {
			bool valid = true;
			for(int j = 0; j < vals.size(); j++) {
				if(!isValid(vals[j][i], field)) {
					valid = false;
					break;
				}
			}
			if(valid) {
				cout << i << " ";
				//count++;
				colValid[field][i] = true;
			}
		}
		cout << endl;
	}

	known[1] = "row";
	known[3] = "train";
	known[4] = "seat";
	known[8] = "class";
	known[9] = "arrival_station";
	known[12] = "duration";
	known[15] = "departure_location";
       	cout << go(vals, fields, cols) << endl;
	long long result = 1;
	for(int i = 0; i < cols.size(); i++) {
		cout << cols[i] << ": " << vals[0][i] << endl;
		if(cols[i].substr(0, 3) == "dep") result *= vals[0][i];
	}
	cout << result << endl;
}
