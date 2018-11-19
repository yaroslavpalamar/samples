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
	bool isOperand(char x) {
		return ((x >= 'a' && x <='z') || (x >= 'A' &&  x <='Z'));
	}
	
public:
	string getPostExp() 
	{
		return postExp;
	}
	explicit PostToPref (string inputExpr)
	{
		this->postExp=inputExpr;
	}

	string postToInfixConv() {
		stack<string> stack;
		for (int i=0; postExp[i]!='\0'; ++i) {
			if (isOperand(postExp[i])) {
				string op(1, postExp[i]);
				stack.push(op);
			} else {
				string op1 = stack.top();
				stack.pop();
				string op2 = stack.top();
				stack.pop();
				stack.push("("+op2+postExp[i]+op1+")");
			}
		}
		return stack.top();
	}
};

int
main(int argc, char** argv)
{
	//PostToPref poToPr("MABC/-AD/L-*-");
	PostToPref poToPr("ab*c+");
	cout << "Postfix: " << poToPr.getPostExp() << endl; 
	cout << "Infix: " << poToPr.postToInfixConv() << endl;

        return 0;
}

