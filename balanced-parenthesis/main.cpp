#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isPair(char open, char close) { //checks if pair of opening or closing brackets balanced or not
    if(open == '(' && close == ')')
        return true;
    else if(open == '{' && close == '}')
        return true;
    else if(open == '[' && close == ']')
        return true;

    return false;
}

bool isBalanced(char* exp) { //scans whole expression to detect brackets
    int i;
    
    stack<char> S; //create a stack object

    while(*exp) {
        if(*exp == '(' || *exp == '{' || *exp == '[') //if opening bracket is detected
            S.push(*exp); //push opening bracket to the stack
        else if(*exp == ')' || *exp == '}' || *exp == ']') { //if closing bracket is detected
            if(S.empty() || !isPair(S.top(), *exp)) //if stack is empty OR top of the stack and closing bracket are not balanced
                return false;
            else
                S.pop(); //pop the opening bracket from top of the stack
        }
        exp++;
    }
    return S.empty() ? true : false; //check is the stack is empty in the end or not
}

int main() {
    char expression[100];
    std::cout<<"Enter the expression to check: ";
    std::cin>>expression;

    if(isBalanced(expression))
        std::cout<<"Balanced";
    else
        std::cout<<"Not Balanced";

    return 0;
}