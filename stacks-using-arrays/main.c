#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100 //maximum stack limit

int arr[MAX_SIZE];
int top = -1; 

void push(int); //inserts elements to top
void pop(void); //deletes top element
void topElement(void); //prints top element
void print(void); //prints stack

int main() {
    int n, i ,x;
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter the number: ");
        scanf("%d",&x);
        push(x);
    }
    print();
    pop();
    print();
    topElement();
    return 0;
}

void push(int num) {
    if(top == MAX_SIZE-1) { //check if stack is full
        printf("Stack Overflow!");
        exit(1);
    }
    arr[++top] = num; //insert element and increment top
    return;
}

void pop() {
    if(top == -1) { //check if stack is empty
        printf("Stack Underflow!");
        exit(1);
    }
    top--; //remove element
    return;
}

void topElement() {
    printf("\nTop element: %d", arr[top]);
    return;
}

void print() {
    int i;
    printf("\nStack: ");
    for(i=0;i<=top;i++) {
        printf("%d",arr[i]);
    }
    return;
}