#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	set<string> fields;
	set<string> valid1, valid2;
	valid1.insert("ecl");
	valid1.insert("pid");
	valid1.insert("eyr");
	valid1.insert("hcl");
	valid1.insert("byr");
	valid1.insert("iyr");
	valid1.insert("cid");
	valid1.insert("hgt");
	valid2.insert("ecl");
	valid2.insert("pid");
	valid2.insert("eyr");
	valid2.insert("hcl");
	valid2.insert("byr");
	valid2.insert("iyr");
	valid2.insert("hgt");
	int count = 0;
	while(cin >> s) {
		if(s == "end") {
			if(fields == valid1 || fields == valid2) count++;
			fields.clear();
		} else {
			fields.insert(s);
		}
	}
	cout << count << endl;
}
