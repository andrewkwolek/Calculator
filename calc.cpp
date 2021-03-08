
#include "Stack.h"
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;


void stack_plus(Stack<double> &stack)
{
	assert(stack.size() >= 2);
    double datum1 = stack.pop();
    double datum2 = stack.pop();
	double datum3 = datum1 + datum2;
    stack.push(datum3);
}

void stack_minus(Stack<double> &stack)
{
	assert(stack.size() >= 2);
    double datum1 = stack.pop();
    double datum2 = stack.pop();
	double datum3 = datum2 - datum1;
    stack.push(datum3);
}

void stack_multiply(Stack<double> &stack)
{
	assert(stack.size() >= 2);
    double datum1 = stack.pop();
    double datum2 = stack.pop();
	double datum3 = datum2 * datum1;
    stack.push(datum3);
}

void stack_divide(Stack<double> &stack)
{
	assert(stack.size() >= 2);
    double datum1 = stack.pop();
    double datum2 = stack.pop();
    if(datum1 == 0)
    {
        cout << "Error: Division by zero" << endl;
        stack.push(datum2);
        stack.push(datum1);
        return;
    }
    
    stack.push(datum2 / datum1);
}

void stack_duplicate(Stack<double> &stack)
{
	assert(stack.size() >= 1);
    double datum = stack.pop();
    stack.push(datum);
    stack.push(datum);
}

void stack_reverse(Stack<double> &stack)
{
	assert(stack.size() >= 2);
    double datum1 = stack.pop();
    double datum2 = stack.pop();
    stack.push(datum1);
    stack.push(datum2);
}

void stack_print(Stack<double> &stack)
{
	assert(stack.size() >= 1);
    cout << stack.top() << endl;
}

void stack_clear(Stack<double> &stack)
{
    while(!stack.empty())
    {
        stack.pop();
    }
}

void stack_print_all(Stack<double> &stack)
{
    stack.print(cout);
    cout << endl;
}

void stack_negate(Stack<double> &stack)
{
    double datum = stack.pop();
    datum = datum * -1;
    stack.push(datum);
}


int main()
{
    //freopen("calc_test00.in","r",stdin);
    cout.precision(4);
    
    Stack<double> stack;
    string input;
    
    while(cin >> input)
    {
        if(input == "q")
        {
			return 0;
        }
        else if(input == "+")
        {
            stack_plus(stack);
        }
        else if(input == "-")
        {
            stack_minus(stack);
        }
        else if(input == "*")
        {
            stack_multiply(stack);
        }
        else if(input == "/")
        {
            stack_divide(stack);
        }
        else if(input == "d")
        {
            stack_duplicate(stack);
        }
        else if(input == "r")
        {
            stack_reverse(stack);
        }
        else if(input == "p")
        {
            stack_print(stack);
        }
        else if(input == "c")
        {
            stack_clear(stack);
        }
        else if(input == "a")
        {
            stack_print_all(stack);
        }
        else if(input == "n")
        {
            stack_negate(stack);
        }
        else
        {
            stack.push(stod(input));
        }
        
    }
    
    return 0;
}
