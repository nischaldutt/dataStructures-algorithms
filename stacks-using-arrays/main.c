#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

int arr[MAX_SIZE];
int top = -1;

void push(int);
void pop(void);
void topElement(void);
void print(void);

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
    if(top == MAX_SIZE-1) {
        printf("Stack Overflow!");
        exit(1);
    }
    arr[++top] = num;
    return;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow!");
        exit(1);
    }
    top--;
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