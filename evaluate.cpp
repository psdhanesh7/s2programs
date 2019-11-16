#include<bits/stdc++.h>
using namespace std;

int isOperator( char );
int performOperation( char, int, int );
int isNumericDigit( char );
int evaluatePostfix( string );
int evaluatePrefix( string );

class Stack
{
	private:

			int s[100], top = -1, size = 100;

	public:
			void push(int value)
			{
				if( top == size)
					return;
				else
				{
					top = top + 1;
					s[top] = value;
				}
			}

			void pop()
			{
				if( top == -1)
					return;
				else
				{
					top--;
				}
			}

			int Top()
			{
				if(top != -1)
				return s[top];
			}

			int isEmpty()
			{
				if(top == -1)
					return 1;
				return 0;
			}

};

int main()
{

	string exp;
	int result,choice;

	while(1)
	{

		cout << "\n____MENU_____\n1.Postfix Expression Evaluation\n2.Prefix Expression Evaluation\n3.Exit\nEnter your choice:" ;
		
		cin >> choice ;

		switch(choice)
		{
			case 1: cout << "Enter a valid Postfix Expression:\n";	
					cin.ignore();				
					getline(cin, exp);
						
					result = evaluatePostfix(exp);

					cout << "Result of the given expression is : " << result << endl;
					break;

			case 2: cout << "Enter a valid Prefix Expression:\n";	
					cin.ignore();				
					getline(cin, exp);
						
					result = evaluatePrefix(exp);

					cout << "Result of the given expression is : " << result << endl;
					break;

			case 3:	goto end;

			default: cout << "Invalid choice!!!" << endl;	

		}


	}
	end:;
	return 0;
}


int isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int performOperation(char optr, int operand1, int operand2)
{
	switch(optr)
	{
		case '*': return operand1 * operand2;

		case '/': return operand1 / operand2;

		case '+': return operand1 + operand2;

		case '-': return operand1 - operand2;
	}
}

int isNumericDigit(char c)
{
	return c >= '0' && c <= '9' ? 1 : 0;
}

int evaluatePrefix(string  exp )
{
	int i, result, length = exp.length(), operand1, operand2, operand;
	Stack s1, s2;

	for(i = length-1 ;i >= 0;i--)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		else if(isOperator(exp[i]))
		{
			operand1 = s1.Top();
			s1.pop();
			operand2 = s1.Top();
			s1.pop();
			result = performOperation(exp[i], operand1, operand2);
			s1.push(result);
		}
		else if(isNumericDigit(exp[i]))
		{
			operand = 0;
			while(isNumericDigit(exp[i]))
			{
				s2.push(exp[i] - '0');
				i--;
			}
			i++;

			while(!s2.isEmpty())
			{
				operand = operand * 10 + s2.Top();
				s2.pop();
	
			}
			
			s1.push(operand);
		}
	}

	result = s1.Top();
	s1.pop();
		
	return result;

}

int evaluatePostfix(string exp)
{
	int i, result, length = exp.length(), operand1, operand2, operand;
	Stack s;

	for(i = 0; i < length; i++)
	{
		if(exp[i] == ' ' || exp[i] == ',')
			continue;
		else if(isOperator(exp[i]))
		{
			operand2 = s.Top();
			s.pop();
			operand1 = s.Top();
			s.pop();
			result = performOperation(exp[i], operand1, operand2);
			s.push(result);
		}
		else if(isNumericDigit(exp[i]))
		{
			operand = 0;
			while(isNumericDigit(exp[i]))
			{
				operand = operand * 10 + (exp[i] - '0');
				i++;
			}
			i--;
			s.push(operand);
		}
	}
	result=s.Top();
	s.pop();
		
	return result;
}

