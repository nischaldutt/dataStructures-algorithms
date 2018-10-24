/**************************************************************************
* 
* 
* Enter the prefix expression with ',' separated list to get the output
*
*
* *************************************************************************/


#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

bool isNumeric(char); //checks weather a character is numeric digit
bool isOperator(char); //checks weather a charackter is an arithmetic operator
int calculate(char, int, char); //performs arithmetic operation on two operands

int evalPostfix(std::string& exp) { //string of expression
    int i;
    stack<int> S; //create a stack object

    for(i=exp.length();i>=0;i--) { //loop from right to left end***

        if(isOperator(exp[i])) { //check if present character is an operator

            int op2 = S.top(); //pop the top of stack which is operand2
            S.pop();

            int op1 = S.top(); //pop another top of stack which is operator1
            S.pop();

            int result = calculate(op1, exp[i], op2); //perform arithemtic operation

            S.push(result); //push the result back to the top of stack
        }
        else if(isNumeric(exp[i])) { //check if the scanned character is a numeric digit

            int operand = 0;
            
            while(isNumeric(exp[i])) { //while the scanned char is a digit

                operand = (operand * 10) + (exp[i] - '0'); //form the operand
                i--; 
            }
            //when a non digit char like ',' is detected, it is skipped

            S.push(operand); //push the operand to the top of the stack
        }
    }
    return S.top(); //return the result which is at the top of stack
}

bool isNumeric(char c) { // Function to verify whether a character is numeric digit
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

bool isOperator(char c) { // Function to verify whether a character is operator symbol or not
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int calculate(char op1, int sign, char op2) { // Function to perform an operation and return output
    if(sign == '+')
        return op2 + op1;
    else if(sign == '-')
        return op2 - op1;
    else if(sign == '*')
        return op2 * op1;
    else if(sign == '/')
        return op2 / op1;
    else 
        std::cout<<"Error";
        return -1;       
}

int main() {
    std::string expression;

    std::cout<<"Enter the prefix expression: ";
    std::cin>>expression;

    int output = evalPostfix(expression);
    std::cout<<"Result: "<<output;
    return 0;
}