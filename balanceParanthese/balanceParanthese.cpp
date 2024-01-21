#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
template <class ttt>
class stack_array {
	int top;
	ttt item[MAX_SIZE];
public:
	stack_array() :top(-1) {}

	void push(ttt Element)
	{
		if (top > 100) { cout << " Array is Full "; }

		else
		{
			top++;
			item[top] = Element;
		}

	}
	bool isEmpty() { return top < 0; }
	void pop()
	{
		if (isEmpty()) { cout << " Array is Empty "; }
		else
		{
			top--;
		}
	}
	void pop(ttt& beforePoping)
	{
		if (isEmpty()) { cout << " Array is Empty "; }
		else
		{
			beforePoping = item[top];
			top--;
		}
		cout << " the valur before pop() is " + beforePoping;
	}
	ttt getTop()
	{
		if (isEmpty()) { cout << " Array is Empty "; }
		else
		{
			return item[top];
		}
	}
	void print()
	{
		for (int i = 0;i <= top;i++)
		{
			cout << item[i] + " ";
		}
	}
};
bool arePair(char open,char close){
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    return false;
}
bool areBalanced(string exp)
{
	stack_array <char> s;
	for (int i = 0;i < exp.length();i++) 
	{
		if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{')
			s.push(exp[i]);
		else if (exp[i] == ']' || exp[i] == ')' || exp[i] == '}')
		{
			if (s.isEmpty() || !arePair(s.getTop(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.isEmpty();
}

int main()
{
	string expression;
	cin >> expression;
	if(areBalanced(expression))
    cout << " Balanced\n";
	else
		cout << "Not Balanced\n";
}
