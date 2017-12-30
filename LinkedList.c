#include<stdio.h>
#include<stdlib.h>

typedef struct Node *Node;
typedef struct Node *List;

struct Node{
    int val;
    Node next;
};

List init(Node head){
    head = malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

void insert(List L,int x){
    Node n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = L->next;
    L->next = n;
}

void printList(List L){
    L = L->next;
    while(L!=NULL){
        printf("%d  ",L->val);
        L = L->next;
    }
}

Node find(List L,int x){
    L = L->next;
    while(L->val != x && L!=NULL){
        L = L->next;
    }
    return L;
}

Node findPrev(List L,int x){

    while(L->next->val != x && L->next != NULL){
        L = L->next;
    }
    return L;
}

void deleteNode(List L,int x){

    Node p = L->next,pre = L,q;
    while(p!=NULL){
        if(p->val == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }else{

            pre = p;
            p = p->next;
        }
    }
}

void sortList(List L){
    Node p = L->next , pre;
    Node r = p->next;

    p->next = NULL;
    p = r;
    while(p!=NULL){
        r = p->next;
        pre = L;

        while(pre->next!=NULL && pre->next->val < p->val){
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

void reverse(List L){
    Node p = L->next,q;

    L->next = NULL;

    while(p!=NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;

        p = q;
    }
}

void deleteMin(List L){
    Node p = L->next;
    Node q = p->next;
    int min = p->val;
    Node MinNode_prev = L,MinNode = p;

    while(q!=NULL){
        if(min > q->val){
            min = q->val;
            MinNode_prev = p;
            MinNode = q;
        }
        p = q;
        q = q->next;
    }

    MinNode_prev->next = MinNode->next;
}

int main(){
    List L;
    L = init(L);
    insert(L,1);
    insert(L,5);
    insert(L,0);
    insert(L,4);
    insert(L,9);
    insert(L,2);


    //deleteNode(L,2);
    //sortList(L);
    printf("the origin List :\n");
    printList(L);

    deleteMin(L);
    printf("\nAfter deleteMin :\n");
    printList(L);

    return 0;
}
