#include <bits/stdc++.h>

using namespace std;

struct Instruction {
	string op;
	int val;
};

class Code {
	public:
	static Code readCode() {
		Code c;
		Instruction i;
		while(cin >> i.op >> i.val) {
			c.instructions.push_back(i);
		}
		return c;
	}
	int exec() {
		while(PC < instructions.size()) {
			if(executed.find(PC) == executed.end())
				execInstruction();
			else
				return ACC;
		}
		return ACC;
	}
	void execInstruction() {
		executed.insert(PC);
		if(instructions[PC].op == "jmp") {
			PC += instructions[PC].val;
			return;
		} else if(instructions[PC].op == "acc") {
			ACC += instructions[PC].val;
		}
		PC++;
	}
	private:
	vector<Instruction> instructions;
	int PC = 0;
	int ACC = 0;
	set<int> executed;
};

int main() {
	Code c = Code::readCode();
	cout << c.exec() << endl;
}
