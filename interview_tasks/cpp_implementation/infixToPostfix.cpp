#include <iostream>
#include <stack>
using namespace std;

/*
Input:  Postfix : MABC/-AD/L-*-
Output: Prefix :  -M*-A/BC-/ADL
Postfix to Infix : M-A-(B/C)*(A/D)-L
*/

class InfixToPost 
{
	string exp;	
	bool isOperand(char x) {
		return ((x >= 'a' && x <='z') || (x >= 'A' &&  x <='Z'));
	}

	// precendence of operators
	int prec (char c)
	{
		if (c=='^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else 
			return -1;
	}
	
public:
	string getInfixExp() 
	{
		return exp;
	}
	explicit InfixToPost (string inputExpr)
	{
		this->exp=inputExpr;
	}

	string infixToPostfixConv() {
		stack<char> stack;
		stack.push('N');
		int l = exp.length();
		string result;
		for (int i = 0; i < l; ++i) {
			if (isOperand(exp[i]))
				result+=exp[i];
			else if (exp[i] == '(')
				stack.push('(');
			else if (exp[i] == ')') {
				while (stack.top() != 'N' && stack.top() !='(') {
					char c = stack.top();
					stack.pop();
					result +=c;
				}
				if (stack.top()== '(') {
					char c = stack.top();
					stack.pop();
				}
			} else {
				while (stack.top() != 'N' && prec(exp[i]) <= prec(stack.top())) {
					char c = stack.top();
					stack.pop();
					result += c;
				}
				stack.push(exp[i]);
			}
		}
		while (stack.top() != 'N') {
			char c = stack.top();
			stack.pop();
			result+=c;
		}
		return result;
	}
};

int
main(int argc, char** argv)
{
	//PostToPref poToPr("MABC/-AD/L-*-");
	InfixToPost iTP("a+b*(c^d-e)^(f+g*h)-i");
	cout << "Infix: " << iTP.getInfixExp() << endl; 
	cout << "Postfix: " << iTP.infixToPostfixConv() << endl;

        return 0;
}

