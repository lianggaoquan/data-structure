#include<stdio.h>
#include<stdlib.h>

typedef struct Node *Node;
typedef struct Node *LoopList;

struct Node{
    int val;
    Node next;
};

LoopList init(LoopList L){
    L = malloc(sizeof(LoopList));
    L->next = L;
    return L;
}

void insert(LoopList L,int val){
    Node p = malloc(sizeof(Node));
    p->val = val;
    p->next = L->next;
    L->next = p;
}

void printList(LoopList L){
    Node q = L->next;
    while(q!=L){
        printf("%d  ",q->val);
        q = q->next;
    }
    printf("\n");
}

void deleteMin(LoopList L){
    Node p,pre,minp,minpre;
    while(L->next!=L){
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;

        while(p!=L){
            if(p->val < minp->val){
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d\n",minp->val);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}


int main(){
    LoopList L;
    L = init(L);

    insert(L,1);
    insert(L,7);
    insert(L,13);
    insert(L,3);

    printList(L);
    deleteMin(L);

    return 0;
}
