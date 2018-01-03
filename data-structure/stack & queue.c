#include<stdio.h>
#include<stdlib.h>

typedef struct stack *stack;

struct stack{
    int capacity;
    int top;
    int *arr;
};

//============================stack======================

stack init_stack(stack s,int capacity){
    s = malloc(sizeof(stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = malloc(sizeof(int)*capacity);

    return s;
}

void push(stack s,int x){
    s->arr[++s->top] = x;
}

int pop(stack s){
    return s->arr[s->top--];
}

int top(stack s){
    return s->arr[s->top];
}

int stack_is_empty(stack s){
    return s->top == -1;
}

//================================queue======================

typedef struct queue *queue;

struct queue{
    int *data;
    int front;
    int rear;
};

queue init_queue(queue q,int capacity){
    q = malloc(sizeof(queue));
    q->front = 0;
    q->rear = 0;
    q->data = malloc(sizeof(int)*capacity);

    return q;
}

int queue_is_empty(queue q){
    if(q->front==q->rear){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(queue q,int x){
    q->data[q->rear] = x;
    q->rear++;
}

int dequeue(queue q){
    return q->data[q->front++];
}

void printQueue(queue q){
    int i;
    for(i=q->front;i<q->rear;i++){
        printf("%d  ",q->data[i]);
    }
    printf("\n");
}

void reverse_queue(queue q){
    stack s;
    s = init_stack(s,10);

    while(queue_is_empty(q)!=1){
        // q is not empty
        push(s,dequeue(q));
    }

    // Now q is empty
    while(stack_is_empty(s)!=1){
        enqueue(q,pop(s));
    }

    printQueue(q);
}



int main(){
    queue q;
    q = init_queue(q,10);

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);

    printf("original queue:\n");
    printQueue(q);
    printf("After reverse:\n");
    reverse_queue(q);

    return 0;
}
