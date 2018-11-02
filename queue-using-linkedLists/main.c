#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int);
void dequeue(void);
void print(void);

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
    node* temp = (node*) malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
    return;
}

void dequeue() {
    node* temp = front;
    if(front == NULL) {
        printf("\nNo element in Queue!");
        return;
    }
    else if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->link;
    }
    free(temp);
    return;
}

void print(void) {
    node* temp = front;
    while(temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    return;
}