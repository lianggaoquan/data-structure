#include<stdio.h>
#include<stdlib.h>

typedef struct stack *stack;

struct stack{
    int capacity;
    int top;
    char *arr;
};

stack init(stack s,int capacity){
    s = malloc(sizeof(stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = malloc(sizeof(char)*capacity);

    return s;
}

void push(stack s,char x){
    s->arr[++s->top] = x;
}

void pop(stack s){
    char e = s->arr[s->top];
    s->top--;
}

char top(stack s){
    return s->arr[s->top];
}

int isEmpty(stack s){
    return s->top == -1;
}

int check(stack s,const char *ch){
    char temp;
    while(*ch!='\0'){
        if(*ch=='['){
            temp = *ch;
            push(s,temp);
        }else if(*ch==']'){
            pop(s);
        }
        ch++;
    }
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }

}

int main(){
    stack s;
    s = init(s,10);
    char ch[6];
    printf("Enter expression:\n");
    scanf("%s",&ch);
    printf("\n");

    int c = check(s,ch);
    if(c==1){
        printf("perfect matched!\n");
    }else{
        printf("Not matched,check it again.\n");
    }
    return 0;
}
