#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

bool isNumeric(char);
bool isOperator(char);
int calculate(char, int, char);

int evalPostfix(char* exp) {
    int i;
    size_t len=0;
    
    while (*exp != '\0') { 
        len++; 
        *exp++; 
    } 
    std::cout<<len;
    
    stack<int> S;

    for(i=0;i<len;i++) {
        if(exp[i] == ',' || exp[i] == ' ')

            continue;

        else if(isOperator(exp[i])) {

            int op2 = S.top();
            S.pop();

            int op1 = S.top();
            S.pop();

            int result = calculate(op1, exp[i], op2);

            S.push(result);
        }
        else if(isNumeric(exp[i])) {

            int operand = 0;
            
            while(i<len && isNumeric(exp[i])) {

                operand = (operand * 10) + (exp[i] - '0');
                i++;
            }
            i--;

            S.push(operand);
        }
    }
    return S.top();
}

bool isNumeric(char c) {
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int calculate(char op1, int sign, char op2) {
    if(sign == '+')
        return op1 + op2;
    else if(sign == '-')
        return op1 - op2;
    else if(sign == '*')
        return op1 * op2;
    else if(sign == '/')
        return op1 / op2;
    else 
        std::cout<<"Error";
        return -1;       
}

int main() {
    char expression[100];

    std::cout<<"Enter the postfix expression: ";
    std::cin>>expression;

    int output = evalPostfix(expression);
    std::cout<<"Result: "<<output;
    return 0;
}