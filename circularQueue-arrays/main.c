#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue(void);
bool isEmpty(void);
bool isFull(void);

int main() {
    int n,x,i;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("Enter the element: ");
        scanf("%d",&x);
        enqueue(x);
    }
    for(i=0;i<n;i++) {
        printf("After delete one element: ");
        dequeue();
    }
    return 0;
}

bool isEmpty() {
    if(front == -1 && rear == -1)
        return true;
    return false;
}

bool isFull() {
    if((rear + 1) % (rear - front + 1) == front) 
        return true;
    return false;
}

void enqueue(int x) {
    if(isFull()) {
        printf("Queue is Full!");
        return;
    }
    else if(isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = x;
    return;
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is already empty!");
        return;
    }
    else if(front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
}