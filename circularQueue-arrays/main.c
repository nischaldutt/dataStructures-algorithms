#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 20

int queue[MAX_SIZE]; //global circular queue
int front = -1; //index pointing to beginning of queue
int rear = -1; //index pointing to end of queue

void enqueue(int); //function that inserts number in the rear
void dequeue(void); //function that removes rear element
bool isEmpty(void); //checks if queue is empty 
bool isFull(void); //check if queue is already full 
void print(void); //prints all elements of queue

int main() {
    int n,x,i;
    printf("\nEnter total number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("\nEnter the element: ");
        scanf("%d",&x);
        enqueue(x);
    }
    printf("\n");
    dequeue();
    printf("\n");
    dequeue();
    return 0;
}

void print() {
    for(int i=front;i<=rear;i++)
        printf("%d\t", queue[i]);
    return;
}

bool isEmpty() {
    if(front == -1 && rear == -1)
        return true;
    return false;
}

bool isFull() {
    if((rear + 1) % MAX_SIZE == front) //check if front and rear both point to same location
        return true;
    return false;
}

void enqueue(int x) {
    if(isFull()) { 
        printf("\nQueue is Full!");
        return;
    }
    else if(isEmpty()) { //if empty then both front and empty will point to same location after insertion
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = x;
    print();
    return;
}

void dequeue() {
    if(isEmpty()) {
        printf("\nQueue is already empty!");
        return;
    }
    else if(front == rear) { //checks if queue has only one element
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
    print();
    return;
}