#include<iostream>
#include<stack>
#include<string>

bool isPair(char open, char close) { //checks if pair of opening or closing brackets balanced or not
    if(open == '(' && close == ')') 
        return true;
    else if(open == '{' && close == '}') 
        return true;
    else if(open == '[' && close == ']') 
        return true;
    
    return false;
}

bool isBalanced(string exp) { //scans whole expression to detect brackets
    int i;
    int len = string.length(exp);
    stack<char> S; //create a stack object

    for(i=0;i<len;i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') //if opening bracket is detected
            S.push(exp[i]); //push opening bracket to the stack
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') { //if closing bracket is detected
            if(S.empty() || !isPair(S.top(), exp[i])) //if stack is empty OR top of the stack and closing bracket are not balanced
                return false; 
            else
                S.pop(); //pop the opening bracket from top of the stack
        }
    }
    return S.empty() ? true : false; //check is the stack is empty in the end or not
}

int main() {
    string expression;
    cout<<"Enter the expression to check: ";
    cin>>expression;

    if(isBalanced(expression))
        return "Balanced";
    else
        return "Not Balanced";
    
    return 0;
}