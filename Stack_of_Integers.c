#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct stack{
    int top;
    int data[SIZE];
    };
typedef struct stack STACK;
void push(STACK *s,int item)
{
    if(s->top==SIZE-1)
        printf("\nStack Overflow\n");
    else{
    s->data[++(s->top)]=item;
    }
}
void pop(STACK *s)
{
    if(s->top==-1)
        printf("\nStack Underflow\n");
    else
        printf("\nPopped element is %d\n",(s->data[(s->top)--]));
}
void display(STACK s)
{
    int i;
    if(s.top==-1)
        printf("\nStack is empty\n");
    else{
        printf("\nThe Stack elements are:\n");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
}
int main()
{
    int ch,item;
    STACK s;
    s.top=-1;
    for(;;)
    {
        printf("\nSTACK OPERATIONS\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
        case 1:printf("\nEnter element:");
               scanf("%d",&item);
               push(&s,item);
               break;
        case 2:pop(&s);
               break;
        case 3:display(s);
               break;
        default:exit(0);
    }
    }
    return 0;
}
