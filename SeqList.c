#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct SeqList{
    int *data;
    int length;
}*SeqList;

SeqList init(int size){
    SeqList L = malloc(sizeof(struct SeqList));
    L->data = malloc(sizeof(int)*size);
    L->length = 0;
    return L;
}

void insert(SeqList L,int i,int e){
    //insert e in i_th position
    int j = 0;
    for(j=i-1;j<L->length;j++){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->length++;
}

void deleteList(SeqList L,int i){
    //delete the i_th element.
    int e = L->data[i-1];
    int j=i;
    for(j=i;j<L->length;j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
}

void printList(SeqList L){
    int j = 0;
    for(j=0;j<L->length;j++){
        printf("%d  ",L->data[j]);
    }
}

int delete_between_s_t(SeqList L,int s,int t){
    //delete element,where s <= elem <= t
    int i,j;
    if(s>=t||L->length==0){
        return 0;
    }

    for(i=0;i<L->length&&L->data[i]<s;i++);

    if(i>=L->length){
        return 0;
    }

    for(j=i;j<L->length&&L->data[j]<=t;j++);

    while(j<L->length){
        L->data[i] = L->data[j];
        i++;
        j++;
    }
    L->length = i;
    return 1;
}

void delete_repeat(SeqList L){
    // the SeqList is ordered.
    int i,j;
    for(i=0,j=1;j<L->length;j++){
        if(L->data[i]!=L->data[j]){
            i++;
            L->data[i] = L->data[j];
        }
    }
    L->length = i+1;
}

SeqList merge(SeqList a,SeqList b){
    SeqList result = malloc(sizeof(struct SeqList));
    result->data = malloc(sizeof(int)*(a->length + b->length));

    int i=0;
    int j=0,k=0;

    while(j<a->length && k<b->length){

        if(a->data[j]>b->data[k] && k<b->length){
            result->data[i] = b->data[k];
            k++;
            i++;
        }
        if(a->data[j]<b->data[k] && j<a->length){
            result->data[i] = a->data[j];
            j++;
            i++;
        }

    }


    while(j<a->length){
        result->data[i] = a->data[j];
        i++;
        j++;
    }
    while(k<b->length){
        result->data[i] = b->data[k];
        i++;
        k++;
    }
    result->length = i;
    return result;
}

// if find,return index,else return -1
int binary_search(SeqList L,int x){
    int left = 0;
    int right = L->length-1;
    int mid = (left+right)/2;
    int found = 0;

    while(L->data[mid]!=x && left!=mid){
        mid = (left+right)/2;
        if(L->data[mid]>x){
            right = mid-1;
        }
        if(L->data[mid]<x){
            left = mid+1;
        }
    }
    if(L->data[mid]==x){
        found = 1;
        return mid;
    }else{
        found = -1;
        return found;
    }

}

void exchange_insert(SeqList L,int x){
    // binary search
    int found_x = binary_search(L,x);
    if(found_x!=-1){
        // find !
        int temp = L->data[found_x];
        L->data[found_x] = L->data[found_x+1];
        L->data[found_x+1] = temp;
    }else{
        // not found
        int j=0;
        for(j=0;x>L->data[j] && j<L->length;j++);
        insert(L,j+1,x);
    }
}

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    SeqList L = init(20);
    int i = 0;

    insert(L,1,2);
    insert(L,2,3);

    insert(L,3,4);
    insert(L,4,278);

    SeqList N = init(20);

    insert(N,1,0);
    insert(N,2,1);
    insert(N,3,15);

    //deleteList(L,2);
    //int e = delete_between_s_t(L,2,3);
    //delete_repeat(L);

    //exchange_insert(L,10);
    //printList(L);

    int a = 1,b = 2;
    swap(&a,&b);
    printf("%d\n",a);
    return 0;
}
