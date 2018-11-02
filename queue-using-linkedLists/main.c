#include<stdio.h>
#include<stdlib.h>

typedef struct Node { //structure of a node
    int data;
    struct Node* link;
} node;

node* front = NULL; //pointer pointing to front of the queue, initially set point to null
node* rear = NULL; //pointer pointing to rear of queue, initially set point to null

void enqueue(int); //function to insert in the front
void dequeue(void); //function to remove from rear
void print(void); //prints all queue

int main() {
    int n,x,i;
    printf("\nEnter total number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("\nEnter the element: ");
        scanf("%d",&x);
        enqueue(x);
    }
    print();
    printf("\nDequeuing...\n");
    dequeue();
    print();
    printf("\nDequeuing...\n");
    dequeue();
    print();
    return 0;
}

void enqueue(int x) {
    node* temp = (node*) malloc(sizeof(node)); //create node dynamically in heap memory
    temp->data = x; //assign data
    temp->link = NULL; 
    if(front == NULL && rear == NULL) { //check if queue is initially empty
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
    return;
}

void dequeue() {
    node* temp = front; //point temp to front of queue
    if(front == NULL) { //check if queue is already empty
        printf("\nNo element in Queue!");
        return;
    }
    else if(front == rear) { //check if queue contains only one element
        front = rear = NULL;
    }
    else {
        front = front->link;
    }
    free(temp); //remove node from dynamic heap memory
    return;
}

void print(void) {
    node* temp = front;
    while(temp != NULL) { //loop until we reach end node
        printf("%d\t", temp->data); //print the element 
        temp = temp->link; //move to next node
    }
    return;
}