#include<iostream>
#include<stack>
#include<string.h>

using namespace std;
// Function to convert Infix expression to postfix
std::string InfixToPostfix(std::string str);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

int main()
{
    std::string str;
cout<<"Enter Infix Expression \n";
cin>>str;
std::string postfix = InfixToPostfix(str);
cout<<"postfix = "<<postfix<<"\n";
}

// Function to evaluate Postfix expression and return output
std::string InfixToPostfix(std::string str)
{
// Declaring a Stack from Standard template library in C++.
stack<char> S;
std::string postfix = ""; // Initialize postfix as empty string.
for(int i = 0;i< str.length();i++) {

    // If character is operator, pop two elements from stack, perform operation and push the result back. 
     if(IsOperator(str[i])) 
    {
        while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),str[i]))
        {
            postfix+= S.top();
            S.pop();
        }
        S.push(str[i]);     
    }
    // Else if character is an operand
    else if(IsOperand(str[i]))
    {
        postfix +=str[i];
    }

    else if (str[i] == '(') 
    {
        S.push(str[i]);
    }

    else if(str[i] == ')') 
    {
        while(!S.empty() && S.top() !=  '(') {
            postfix += S.top();
            S.pop();
        }
        S.pop();
    }
}

while(!S.empty()) {
    postfix += S.top();
    S.pop();
}

return postfix;

}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
if(C >= '0' && C <= '9') return true;
if(C >= 'a' && C <= 'z') return true;
if(C >= 'A' && C <= 'Z') return true;
return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
if(C == '+' || C == '-' || C == '*' || C == '/' )
return true;

return false;

}

// Function to verify whether an operator is right associative or not.
bool IsRightAssociative(char op)
{

return false;

}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
int weight = -1;
switch(op)
{
case '+':
case '-':
weight = 1;
break;
case '*':
case '/':
weight = 2;
}
return weight;
}

// Function to check precedence and associativity
int HasHigherPrecedence(char op1, char op2)
{
int op1Weight = GetOperatorWeight(op1);
int op2Weight = GetOperatorWeight(op2);

// If operators have equal precedence, return true if they are left associative. 
// return false, if right associative. 
// if operator is left-associative, left one should be given priority. 

if(op1Weight == op2Weight)
{
if(IsRightAssociative(op1)) return false;
else return true;
}
return op1Weight > op2Weight ? true: false;

}