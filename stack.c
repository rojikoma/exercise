#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


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
}

int pop(struct ArrayStack *S)
{
    if(isEmptyStack(S)) {
        printf("stack is empty\n");
        return INT_MIN;
    }

    return S->array[S->top--];
}

void displayStack(struct ArrayStack *S)
{
    int i;

    if(isEmptyStack(S)) printf("nothing to show\n");

    for(i=0; i<=S->top; i++){
        printf("stack entry = %d\n", S->array[i]);
    }
}

void printMenu()
{
    printf("stack operation\n");
    printf("================\n");
    printf(" (p)ush\n");
    printf("  p(o)p\n");
    printf(" (d)isply stack\n");
    printf(" (e)xit\n");
}

int main()
{
    struct ArrayStack *S = NULL;
    int i, data;
    char choice;

    S = createStack();

    if(!S) printf("Stack creation failed\n");

    while(choice != 'e') {
        printMenu();
        scanf("%c", &choice);

        switch(choice) {
            case 'p' :
                printf("enter data\n");
                scanf("%d", &data);
                push(data, S);
                break;
            case 'o' :
                printf("poped data = %d\n", pop(S));
                break;
            case 'd' :
                displayStack(S);
                break;
            case 'e' :
                break;
        }
    }
    return 0;
}
