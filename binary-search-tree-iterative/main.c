#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BstNode { //strucuture of single node of a binary search tree
    int data; //data portion
    struct BstNode* left; //pointer to the left child
    struct BstNode* right; //pointer to the right child
} BstNode;

BstNode* createNewNode(int);
BstNode* insert(BstNode*,int);
bool search(BstNode*,int);

int main() {
    int n;
    BstNode* root = NULL; //root of the tree initialised to null

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 22);

    printf("Enter the number to search: ");
    scanf("%d", &n);

    if(search(root, n)) {
        printf("Found\n");
    }
    else {
        printf("Not Found\n");
    }

    return 0;
}

BstNode* createNewNode(int num) {
    BstNode* temp = (BstNode*) malloc(sizeof(BstNode)); //create a BST node dynamically in heap memory
    temp->data = num; //assign the number to data portion of the node
    temp->left = NULL; //assign null address to left and right child of the node, these will be adjusted later accordingly
    temp->right = NULL;
    return temp; //return the address of newly created node
}

BstNode* insert(BstNode* root, int num) {
    if(root == NULL) { //check if tree is empty
        root = createNewNode(num); //if yes, then insert the node at the root
        return root;
    }
    else if(num <= root->data) { //check if the number to be inserted is less than or equal to present parent node
        BstNode* parent;
        parent->left = createNewNode(num);
        return parent->left;
    }
    else { //similarly do for the right child
        BstNode* parent;
        parent->right = createNewNode(num);
        return parent->right;
    }
    return root;
}

bool search(BstNode* root, int data) {
    if(root == NULL) { //check if tree is already empty
        return false;
    }
    else if(root->data == data) { //if data to be searched is same as present node then return true
        return true;
    }
    else if(data <= root->data) {
        return search(root->left, data); //if number to be searched is less than the present node then move to the left child
    }
    else {
        return search(root->right, data); //if number to be searched is more than the present node then move to the right child
    }
}