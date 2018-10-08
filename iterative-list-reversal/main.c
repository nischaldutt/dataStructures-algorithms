#include<stdio.h>
#include<stdlib.h>

void insert(int, int); //function that inserts the node at the specified position in the list
void print(void); //function that prints the list
void reverse(void); //funtion reverses a list iteratively

//structure of a node in a list
typedef struct Node {
    int data;
    struct Node* link;
} node;

//head pointer that points to Node type
node* head;

int main() {
    head = NULL; //head initialzed to null
    printf("\nEnter the total number of elements: ");
    int n, i, pos, x, dpos;
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("\nEnter the number: ");
        scanf("%d",&x);
        printf("\nEnter the position: ");
        scanf("%d",&pos);
        insert(x, pos);
    }
    printf("\nOriginal Linked List: \t");
    print();
    reverse();
    printf("\nReversed Linked List: \t");
    print();
    printf("\n");
    return 0;
}

void insert(int num, int pos) {
    int j;
    node* temp1 = (node*)malloc(sizeof(node)); //pointer that points to dynamically created node in memory
    (*temp1).data = num; //assign the number to the data field of node
    (*temp1).link = NULL;
    if(pos == 1) {
        (*temp1).link = head;
        head = temp1;
        return;
    }

    node* temp2 = head;
    for(j=0;j<pos-2;j++) { //loop till pos-1** position of th list, node at position pos-2 points to pos-1 node
        temp2 = (*temp2).link;
    }
    (*temp1).link = (*temp2).link;
    (*temp2).link = temp1;
}

void print() {
    node* temp = head;
    while(temp != NULL) {
        printf("%d", (*temp).data);
        temp = (*temp).link; //move forward from one node to another
    }
}

void reverse() {
    node *prev, *current, *next;
    current = head;
    prev = NULL;

    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return;
}