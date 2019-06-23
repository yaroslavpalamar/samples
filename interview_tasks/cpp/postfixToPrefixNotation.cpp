#include <iostream>
#include <stack>
using namespace std;

/*
Input:  Postfix : MABC/-AD/L-*-
Output: Prefix :  -M*-A/BC-/ADL
Postfix to Infix : M-A-(B/C)*(A/D)-L
*/

class PostToPref 
{
	string postExp;	
	bool isOperator(char x) {
		switch (x) {
		case '+':
		case '-':
		case '/':
		case '*':
			return true;
		}
		return false;
	}
	
public:
	string printPostExp() 
	{
		return postExp;
	}
	explicit PostToPref (string inputExpr)
	{
		this->postExp=inputExpr;
	}

	string postToPreConv() {
		stack<string> stack;
		int length = postExp.size();
		for (int i = 0; i < length; ++i) {
			if (isOperator(postExp[i])) {
				string op1 = stack.top();
				stack.pop();
				string op2 = stack.top();
				stack.pop();
				
				string temp = postExp[i] + op2+op1;
				stack.push(temp);
			} else {
				stack.push(string(1, postExp[i]));
			}
		}
		return stack.top();
	}
};

int
main(int argc, char** argv)
{
	//PostToPref poToPr("MABC/-AD/L-*-");
	PostToPref poToPr("abc++");
	cout << "Postfix: " << poToPr.printPostExp() << endl; 
	cout << "Prefix: " << poToPr.postToPreConv() << endl;

        return 0;
}

