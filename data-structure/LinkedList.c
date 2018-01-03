#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

void delete_between(List L,int a,int b){
    Node p = L->next,q = p->next;
    while(q!=NULL){
        if(a <= q->val && q->val <= b){
            p->next = q->next;
        }
        p = q;
        q = q->next;
    }
}

void printByOrder(List L){
    Node p = L->next;
    Node r = p->next;
    Node prev;

    p->next = NULL;
    p = r;

    while(p!=NULL){
        r = p->next;
        prev = L;
        while(prev->next!=NULL && prev->next->val < p->val){
            prev = prev->next;
        }
        p->next = prev->next;
        prev->next = p;
        p = r;
    }

    p = L->next;
    while(p!=NULL){
        printf("%d  ",p->val);
        p = p->next;
    }
}

/**
分割奇偶元素
*/
void split(List L){
    List odd;
    List even;

    odd = init(odd);
    even = init(even);

    int i = 0;
    Node p = L->next;
    Node r_odd = odd , r_even = even;

    while(p!=NULL){
        i++;
        if(i%2!=0){
            r_odd->next = p;
            r_odd = p;
        }else{
            r_even->next = p;
            r_even = p;
        }
        p = p->next;

    }
    r_odd->next = NULL;
    r_even->next = NULL;
    printf("序号为奇数的元素：\n");
    printList(odd);
    printf("\n序号为偶数的元素：\n");
    printList(even);
}

/**
删除重复元素
*/
void delete_repeat(List L){
    Node p = L->next,q;

    while(p->next!=NULL){
        q = p->next;        //q is the rail of p
        if(p->val==q->val){
            p->next = q->next;
            free(q);
        }else{
            p = p->next;
        }

    }
}

/**
两个元素递增的链表，利用原有链表的空间，处理为单个元素递减的链表
*/
void special_sort(List a,List b){
    Node pa = a->next,pb = b->next;
    Node ra = pa->next,rb = pb;

    while(rb->next!=NULL){
        rb = rb->next;
    }

    pa->next = NULL;
    rb->next = ra;

    Node t;

    while(pb!=NULL){
        //first,find the insert position
        t = pb->next;
        pa = a;         //head of a
        while(pa->next!=NULL && pb->val < pa->next->val){
            pa = pa->next;
        }
        pb->next = pa->next;
        pa->next = pb;

        pb = t;
    }

    printf("\nAfter special_sort:\n");

    printList(a);
}

/**
查找两个链表的公共元素
*/
void find_common_refer(List a,List b){
    Node p = a->next,q = b->next;
    List c;
    c = init(c);

    Node r = c;
    Node t;
    while(p!=NULL && q!=NULL){
        if(p->val < q->val){
            p = p->next;
        }else if(p->val > q->val){
            q = q->next;
        }else{
            t = malloc(sizeof(Node));
            t->val = p->val;
            r->next = t;
            r = t;

            p = p->next;
            q = q->next;
        }

    }
    r->next = NULL;

    printList(c);
}

int find_backward_k(List L,int k){
    int find = 0;
    Node p = L;
    int count = 0,temp;
    while(p->next!=NULL){
        p = p->next;
        count++;
    }

    temp = count-k+1;
    p = L;
    if(temp > 0){
        for(;temp>0;temp--){
            p = p->next;
        }
        find = 1;
        printf("The backward k_th val is:%d\n",p->val);
    }

    return find;
}

/**
查找倒数第k个结点的元素值
*/
int find_back_k_refer(List L,int k){
    Node p = L->next,q = L->next;
    int count = 0;
    while(p!=NULL){
        if(count<k){
            count++;
        }else{
            q = q->next;    //q move count-k times
        }
        p = p->next;
    }
    if(count<k){
        return 0;
    }else{
        printf("%d\n",q->val);
        return 1;
    }
}

/**
当链表中含有多个绝对值相等的元素时，保留第1个，删除其它结点,O(n^2)
*/
void delete_abs_same(List L){
    Node p = L,q;
    Node q_prev;

    while(p->next!=NULL){
        p = p->next;
        q_prev = p;
        while(q_prev->next!=NULL){
            q = q_prev->next;
            if(abs(q->val)!=abs(p->val)){
                q_prev = q;
            }else{
                q_prev->next = q->next;
                free(q);
            }
        }
    }

    printList(L);
}

/**
功能同delete_abs_same(),用空间换时间,时间复杂度:O(n)
假设 |data| < n
*/
void delete_abs_same_refer(List L,int n){
    Node p = L,q;
    int *cache;
    cache = malloc(sizeof(int)*(n+1));
    int i=0;
    for(i=0;i<n+1;i++){
        cache[i] = 0;
    }

    while(p->next!=NULL){
        if(cache[abs(p->next->val)]==0){
            cache[abs(p->next->val)] = 1;
            p = p->next;
        }else{
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }

    printList(L);
}

int main(){
    List a;

    a = init(a);

    insert(a,4);
    insert(a,4);
    insert(a,4);
    insert(a,-3);
    insert(a,-1);
    insert(a,8);
    insert(a,3);
    insert(a,1);
    insert(a,3);
    insert(a,1);

    printf("the original list:\n");
    printList(a);
    printf("\nAfter delete abs_same:\n");
    delete_abs_same_refer(a,9);
    printf("\n");
    delete_abs_same(a);
    return 0;
}
