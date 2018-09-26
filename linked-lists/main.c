#include<stdio.h>
#include<stdlib.h>

void insert(int, int); //function that inserts the node at the specified position in the list
void delete(int); //function delete the node from the list
void print(void); //function that prints the list

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
    print();
    printf("\nEnter the position to delete element: ");
    scanf("%d", &dpos);
    delete(dpos);
    print();
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

void delete(int pos) {
    node* temp1 = head;

    if(pos == 1) { //special case to delete the first node
        head = (*temp1).link; //adjust links to remove the node from list 
        free(temp1); //delete node from memory
        return;
    }

    int i;
    for(i=0;i<pos-2;i++) { //loop till pos-1** position of th list, node at position pos-2 points to pos-1 node
        temp1 = (*temp1).link;
    }
    node* temp2 = (*temp1).link; //adjust links to remove the node from list 
    (*temp1).link = (*temp2).link; //delete node from memory
    free(temp2);
}
