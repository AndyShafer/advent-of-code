#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
		while(PC < instructions.size()) {
			execInstruction();
		}
		return ACC;
	}
	void execInstruction() {
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
};

int main() {
}
