#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct Node *Node;
typedef struct Node *Tree;

struct Node{
    int val;
    Node left;
    Node right;
};

Node insert(Tree t,int x){
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

/**
 * use level traversial to find the max height
 * @param t
 * @return
 */
int MaxLen(Tree t){

    if(!t){
        return 0;
    }

    int front = -1,rear = -1;
    int level = 0,last = 0;
    Node Q[MAXSIZE];
    Q[++rear] = t;
    Node p;

    while(front < rear){
        p = Q[++front];

        if(p->left != NULL){
            Q[++rear] = p->left;
        }
        if(p->right != NULL){
            Q[++rear] = p->right;
        }

        if(front==last){
            level++;
            last = rear;
        }
    }
    return level;

}

/**
 * use level traversial to judge whether the tree is complete binary tree or not
 * @param t
 * @return
 */
int is_complete_BT(Tree t){
   if(!t){
       return 1;
   }

    Node Q[MAXSIZE],p;
    int front = -1,rear = -1;

    Q[++rear] = t;

    while(front < rear){
        p = Q[++front];
        if(p){
            Q[++rear] = p->left;
            Q[++rear] = p->right;
        }else{
            while(front < rear){
                p = Q[++front];
                if(p){
                    return 0;
                }
            }
        }
    }
    return 1;
}



int main() {
    Tree t;
    t = insert(t,10);
    t = insert(t,5);
    t = insert(t,13);
    t = insert(t,9);
    t = insert(t,12);
    t = insert(t,8);
    t = insert(t,7);
    printf("%d ",is_complete_BT(t));
    return 0;
}
