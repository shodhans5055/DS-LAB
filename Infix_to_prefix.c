#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20
struct stack{
    int top;
    char data[SIZE];
} ;
typedef struct stack STACK;
void push(STACK *s,char item)
{
    s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
    return(s->data[(s->top)--]);
}
int preced(char symbol)
{
    switch(symbol)
    {
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 3;
    case '^':return 5;
    }
}
void infixtoprefix(STACK *s,char infix[20])
{
    int i,j=0,len;
    char symbol,prefix[20],temp;
    len=strlen(infix);
    for(i=len-1;i>=0;i--)
    {
        symbol=infix[i];
        if (isalnum(symbol))
            prefix[j++]=symbol;
        else
        {
            switch(symbol)
            {
                case ')':push(s,symbol);
                         break;
                case '(':temp=pop(s);
                         while(temp!=')')
                         {
                             prefix[j++]=temp;
                             temp=pop(s);
                         }
                         break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':if(s->top==-1||s->data[s->top]==')'){
                          push(s,symbol);}
                         else
                         {
                             while(preced(s->data[s->top])>preced(symbol)&&s->top!=-1&&s->data[s->top]!=')')
                             {
                                 prefix[j++]=pop(s);
                             }
                             push(s,symbol);
                         }
                         break;
            }
        }
    }
   while(s->top!=-1)
   {
       prefix[j++]=pop(s);
   }
   prefix[j]='\0';
   strrev(prefix);
   printf("Prefix Expression is %s\n",prefix);

}
int main()
{
    char infix[20];
    STACK s;
    s.top=-1;
    printf("\nEnter infix expression:\n");
    scanf("%s",infix);
    infixtoprefix(&s,infix);
    return 0;
}
