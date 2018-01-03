#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode *Node;

struct TreeNode{
    char val;
    Node left;
    Node right;
};

Node init_node(char val){
    Node n = malloc(sizeof(Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

typedef struct stack{
    int capacity;
    int top;
    Node *arr;
}*stack;

stack init_stack(int MaxSize){
    stack s = malloc(sizeof(struct stack));
    s->arr = malloc(sizeof(struct TreeNode)*MaxSize);
    s->capacity = MaxSize;
    s->top = -1;
    return s;
}

void push(stack s,Node x){
    s->top++;
    s->arr[s->top] = x;
}

void pop(stack s){
    printf("%c\n",s->arr[s->top]->val);
    s->top--;
}

Node top(stack s){
    return s->arr[s->top--];
}

Node ExpreTree(const char *ch){
    Node p;
    stack s = init_stack(20);
    int i=0;

    while(*ch!='\0'){
        p = malloc(sizeof(Node));
        if(*ch>='0'&&*ch<='9'||*ch>='a'&&*ch<='z'){
            p->val = *ch;
            p->left = NULL;
            p->right = NULL;
            push(s,p);
        }else if(*ch=='+'||*ch=='-'||*ch=='*'||*ch=='/'){
            p->val = *ch;
            p->right = top(s);
            p->left = top(s);
            push(s,p);
        }
        ch++;
    }
    return p;
}

void traverse(Node T){
    if (T->left!=NULL){
        traverse(T->left);
    }

    putchar(T->val);

    if(T->right!=NULL){
        traverse(T->right);
    }
}


int main(){

    printf("Enter expression:\n");
    char s[20];
    scanf("%s",&s);
    Node temp = ExpreTree(s);

    traverse(temp);
    return 0;
}
