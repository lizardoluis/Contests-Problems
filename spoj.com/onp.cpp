#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

string convert(string input);

int main(int argc, char *argv[])
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        string str, str2;
        cin>>str;
        str2 = convert(str);
        cout<<str2<<"\n";
    }

    return 0;
}

string convert(string input) {
	stack<char> stackOperator;
	queue<char> queueOutput;
	string operators = "+-*/^";
	string res;
	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i])) {
			queueOutput.push(input[i]);
		} else if (operators.find(input[i]) != string::npos) {
			while (stackOperator.size() > 0 && operators.find(stackOperator.top()) != string::npos
								 && (operators.find(input[i]) <= operators.find(stackOperator.top()))) {
				queueOutput.push(stackOperator.top());
				stackOperator.pop();
			}
			stackOperator.push(input[i]);
		} else if (input[i] == '(') {
			stackOperator.push('(');
		} else if (input[i] == ')') {
			while (!stackOperator.empty()) {
				if (stackOperator.top() == '(') {
					stackOperator.pop();
			 		break;
				}
				queueOutput.push(stackOperator.top());
				stackOperator.pop();
			}
		}
	}

	while (!stackOperator.empty()) {
		queueOutput.push(stackOperator.top());
		stackOperator.pop();
	}

	while (!queueOutput.empty()) {
		res += queueOutput.front();
		queueOutput.pop();
	}

	return res;
}



