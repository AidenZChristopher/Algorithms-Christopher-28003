// University of Arkansas at Little Rock
// Department of Computer Science
// CPSI 28003: Algorithms
// Fall 2026
// Project 2: Infix to Postfix Conversion, Bonus: Evaluate the arithmetic expressions for
// the results. This program is not menu-driven.
// Due Date: April 23, 2026
// Name:
// ID-number (Last 4 Digits):
// Description of the Program (2-3 sentences):
//   This program reads infix arithmetic expressions from the user and converts
//   them to postfix (Reverse Polish Notation) using a stack-based shunting-yard
//   algorithm. The bonus Evaluate function computes the integer result of the
//   postfix expression using a second stack.
// Date Written:
// Date Revised:

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

string InfixToPostfix(char* str);

char* AddDelimetersToStr(char* str)
{
    int spacesNeeded = 0;
    int length = 0;

    while (str[length] != '\0')
    {
        if (str[length] != ' ')
            spacesNeeded = spacesNeeded + 1;
        length = length + 1;
    }

    int size = length + spacesNeeded + 1;
    char* adjustedStr = new char[size];

    int newInx = 0;
    for (int inx = 0; inx < length; inx++)
    {
        if (str[inx] != ' ')
        {
            adjustedStr[newInx] = str[inx];
            newInx = newInx + 1;
            adjustedStr[newInx] = ' ';
            newInx = newInx + 1;
        }
    }
    adjustedStr[newInx] = '\0';

    return adjustedStr;
}

//getPrecedence
//  Establishes operator precedence. * and / are higher than + and -.

int getPrecedence(const string& op)
{
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

//isOperator
//  Returns true if the token is one of the four basic operators.

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

//InfixToPostfix
//  Implements the shunting-yard algorithm to convert infix expressions to postfix.
//  Operands are added directly to the output string.
//  Operators are pushed onto the stack
//  When an operator is encountered, operators with higher or equal precedence are popped from the stack to the output 
//  until a lower precedence operator or a left parenthesis is found.

string InfixToPostfix(char* str)
{
    stack<string> opStack;
    string result = "";
    string token;
    istringstream stream(str);

    while (stream >> token)
    {
        if (token == "(")
        {
            opStack.push(token);
        }
        else if (token == ")")
        {
            // Pop operators until the matching '(' is found.
            while (!opStack.empty() && opStack.top() != "(")
            {
                result += opStack.top() + " ";
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();    //if there is no matching '(' then discard it
        }
        else if (isOperator(token))
        {
            while (!opStack.empty() && opStack.top() != "(" && getPrecedence(opStack.top()) >= getPrecedence(token))
            {
                result += opStack.top() + " ";
                opStack.pop();
            }
            opStack.push(token);
        }
        else
        {
            result += token + " "; // operand with a space goes to result
        }
    }

    //catches any remaining operators on the stack and adds them to the result.
    while (!opStack.empty())
    {
        result += opStack.top() + " ";
        opStack.pop();
    }
    //removes additonal space.
    if (!result.empty() && result.back() == ' ')
        result.pop_back();

    return result;
}

//Evaluate
//  Operands are pushed onto the stack.
//  When an operator is encountered two operands are popped

int Evaluate(string postfix)
{
    stack<int> valStack;
    string token;
    istringstream stream(postfix);

    while (stream >> token)
    {
        if (isOperator(token))
        {
            int rightVal = valStack.top(); valStack.pop(); // right operand
            int leftVal  = valStack.top(); valStack.pop(); // left operand

                 if (token == "+") valStack.push(leftVal + rightVal);
            else if (token == "-") valStack.push(leftVal - rightVal);
            else if (token == "*") valStack.push(leftVal * rightVal);
            else if (token == "/") valStack.push(leftVal / rightVal);
        }
        else
        {
            valStack.push(stoi(token));
        }
    }
    return valStack.top();
}

//main 

int main()
{
    // input arithmetic expression should be less than 80 characters 
    char* str = new char[80];
    while (1) // type ccontrol_c to exit the loop 
    {
        // assuming legal arithemic expressions only 
        cout << "Enter an arithmetic equation..." << endl;
        cin.getline(str, 80);
        str = AddDelimetersToStr(str);
        cout << InfixToPostfix(str) << endl;
        cout << Evaluate(InfixToPostfix(str)) << endl;
    }
    return 0;
}