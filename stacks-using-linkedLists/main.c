#include<stdio.h>
#include<stdlib.h>

typedef struct Node { //structure of a node
    int data;
    struct Node* link;
} node;

node* top; //top of the stack

void push(int);//inserts at the top of stack
void pop(void);//pops from top of stack
void print(void);//prints stack

int main() {
    top = NULL;
    int n,i,x;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("Enter the number: ");
        scanf("%d", &x);
        push(x);
    }
    print();
    pop();
    print();
    return 0;
}

void push(int num) {
    node* temp = (node*) malloc(sizeof(node));//create node dynamically in heap memory
    temp->data = num;//assign data
    temp->link = top;//make node point to next node
    top = temp;//make top point to newly created node
    return;
}

void pop() {
    node* temp = top;
    if(top == NULL)//check if stack is empty
        return;
    top = temp->link;
    free(temp);//delete node from heap memory
    return;
}

void print() {
    printf("\nStack: ");
    node* temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);//print elements
        temp = temp->link;//point to next node in stack
    }
    return;
}