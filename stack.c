#include <stdlib.h>
#include <stdio.h>


struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *createStack()
{
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));

    if (!S) return NULL;

    S->capacity = 1;
    S->top = -1;
    S->array = malloc(sizeof(int) * S->capacity);
    
    if(!S->array) return NULL;
    return S;
}

int isEmptyStack(struct ArrayStack *S) { return(S->top == -1); }
int isFullStack(struct ArrayStack *S) { return(S->top == S->capacity-1); }

void doubleStack(struct ArrayStack *S)
{
    S->capacity *=2;
    S->array = realloc(S->array, S->capacity);
}

void push(int data, struct ArrayStack *S)
{
    if(isFullStack(S)) doubleStack(S);

    S->array[++S->top] = data;
    printf("top = %d\n", S->top);
}

void displayStack(struct ArrayStack *S)
{
    int i;

    if(isEmptyStack(S)) printf("nothing to show\n");

    for(i=0; i<=S->top; i++){
        printf("stack entry = %d\n", S->array[i]);
    }
}

int main()
{
    struct ArrayStack *S = NULL;
    S = createStack();

    if(!S) printf("Stack creation failed\n");

    push(1, S);
    push(9, S);
    push(4, S);

    displayStack(S);
    
    return 0;
}
