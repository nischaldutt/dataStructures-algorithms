#include <stdio.h>
#include <stdlib.h>

void insert(int); //function that inserts the node at the begining of linked list
void print(void); //function that prints the list

//structure of a node in a list
struct Node {
    int data;
    struct Node* link;
} Node;

//head pointer that points to Node type
struct Node* head;

int main()
{
    head = NULL; //head initialzed to null
    printf("\nEnter total number of elements: ");
    int n = 0 , i, x;
    scanf("%d", &n);
    
        for(i=0;i<n;i++) {
            printf("\nEnter the number: ");
            scanf("%d", &x);
            insert(x);
            print();
        }
    return 0;
}

void insert(int num) {
    struct Node* temp = (struct Node*)malloc(sizeof(Node)); //pointer that points to dynamically created node in memory
    (*temp).data = num; //assign the number to the data field of node
    (*temp).link = head; //set link portion to point to the next node
    head = temp; //point the head pointer to the begin
}

void print() {
    struct Node* temp = head; //create a temporary pointer that points to the beginning of the list
    while(temp!=NULL) { //while end node is not reached
        printf("%d", (*temp).data); //print the element
        temp = (*temp).link; //make pointer point to next node
    }
}