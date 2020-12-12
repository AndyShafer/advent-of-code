#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, s1;
	set<string> fields;
	map<string, string> values;
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
	set<string> eyeColors;
	eyeColors.insert("amb");
	eyeColors.insert("blu");
	eyeColors.insert("brn");
	eyeColors.insert("gry");
	eyeColors.insert("grn");
	eyeColors.insert("hzl");
	eyeColors.insert("oth");
	int count = 0;
	while(cin >> s) {
		if(s == "end") {
			if(fields == valid1 || fields == valid2) {
				int byr = stoi(values["byr"]);
				int iyr = stoi(values["iyr"]);
				int eyr = stoi(values["eyr"]);
				bool hgtValid = values["hgt"].size() > 2;
				if(hgtValid) {
					string hgtUnit = values["hgt"].substr(values["hgt"].size()-2);
					int hgt = stoi(values["hgt"].substr(0, values["hgt"].size()-2));
					if(hgtUnit == "in") {
						hgtValid = hgt >= 59 && hgt <= 76;
					} else if(hgtUnit == "cm") {
						hgtValid = hgt >= 150 && hgt <= 193;
					} else {
						hgtValid = false;
					}
				}
				string hcl = values["hcl"];
				bool hclValid = hcl.size() == 7 && hcl[0] == '#';
				for(int i = 1; i < 7; i++) {
					if((hcl[i] < '0' || hcl[i] > '9') && (hcl[i] < 'a' || hcl[i] > 'f'))
						hclValid = false;
				}
				string pid = values["pid"];
				bool pidValid = pid.size() == 9;
				for(int i = 0; i < pid.size(); i++) {
					if(pid[i]  < '0' || pid[i] > '9') pidValid = false;
				}
				if(byr >= 1920 && byr <= 2002 &&
						iyr >= 2010 && iyr <= 2020 &&
						eyr >= 2020 && eyr <= 2030 &&
						hgtValid && hclValid &&
						eyeColors.find(values["ecl"]) != eyeColors.end() &&
						pidValid)
					count++;
			}
			fields.clear();
			values.clear();
		} else {
			cin >> s1;
			fields.insert(s);
			values[s] = s1;
		}
	}
	cout << count << endl;
}
