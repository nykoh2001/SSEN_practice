#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace::std;

string input;
stack<char> stick;

int total_stick;

int main(void) {
	freopen("10_data.txt", "r", stdin);

	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		char ch = input[i];
		if (ch == '(') {
			//total_stick++;
			stick.push(ch);
			continue;
		}

		// if (ch == ')') 
		// NOTE: 레이저인지, 막대의 끝부분인지 구분 필요
		char top_ch = stick.top();
		stick.pop();
		int delta = input[i-1] == '(' ? stick.size() : 1;
		//cout << "total_stick: " << total_stick << " + " << delta << " = " << total_stick + delta << endl;
		total_stick += delta;
	}

	cout << total_stick;

	return 0;
}

#endif
