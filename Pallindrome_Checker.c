#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
struct stack {
    int top;
    char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s, char value) {
        s->top++;
        s->data[s->top] = value;
}
char pop(STACK *s) {
        return s->data[(s->top)--];
    }
int main() {
    char input_string[SIZE],ch;
    int length,mid,i;
    STACK s;
    s.top = -1;
    printf("Enter a string to check if it's a palindrome:\n");
    scanf("%s", input_string);
    length = strlen(input_string);
    mid = length / 2;
    for (i = 0; i < mid; i++) {
        push(&s, input_string[i]);
    }
    if (length % 2 != 0) {
        i++;
    }
    while (input_string[i] != '\0') {
        ch = pop(&s);
        if (ch != input_string[i]) {
            printf("The string \"%s\" is not a palindrome.\n", input_string);
            return 0;
        }
        i++;
    }
    printf("The string \"%s\" is a palindrome.\n", input_string);
    return 0;
}
