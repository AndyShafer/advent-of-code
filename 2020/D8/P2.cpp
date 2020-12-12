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
		PC = 0;
		ACC = 0;
		executed = set<int>();
		while(PC < instructions.size()) {
			if(executed.find(PC) == executed.end())
				execInstruction();
			else
				return -1;
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
	int fixProgram() {
		for(int i = 0; i < instructions.size(); i++) {
			if(instructions[i].op == "jmp") {
				instructions[i].op = "nop";
				int a = exec();
				if(a == -1) {
					instructions[i].op = "jmp";
				} else {
					return a;
				}
			} else if(instructions[i].op == "nop") {
				instructions[i].op = "jmp";
				int a = exec();
				if(a == -1) {
					instructions[i].op = "nop";
				} else {
					return a;
				}
			}
		}
		return -1;
	}
	private:
	vector<Instruction> instructions;
	int PC = 0;
	int ACC = 0;
	set<int> executed;
};

int main() {
	Code c = Code::readCode();
	cout << c.fixProgram() << endl;
}
