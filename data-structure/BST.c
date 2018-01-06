#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Node;

struct Node{
    int val;
    Node left;
    Node right;
};

Node insert(Node t,int x){
    if(t==NULL){
        t = malloc(sizeof(Node));
        t->val = x;
        t->left = NULL;
        t->right = NULL;
    }else{
        if(x > t->val){
            t->right = insert(t->right,x);
        }else if(x < t->val){
            t->left = insert(t->left,x);
        }
    }
    return t;
}

void printTree(Node t){
    if(t->left != NULL){
        printTree(t->left);
    }
    printf("%d  ",t->val);
    if(t->right != NULL){
        printTree(t->right);
    }
}

int main() {
    Node t;
    t = insert(t,1);
    t = insert(t,2);
    t = insert(t,0);
    printTree(t);
    return 0;
}