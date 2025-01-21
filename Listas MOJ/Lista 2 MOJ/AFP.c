#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1000

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char symbol) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Erro: Estouro de pilha!\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = symbol;
}

void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("nil\n");
    } else {
        for (int j = 0; j <= stack->top; j++) {
            printf("%c", stack->data[j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_STACK_SIZE];
    while (scanf("%s", input) != EOF) {
        Stack stack;
        initialize(&stack);

        int i = 0;
        while (input[i] != '\0') {
            if (input[i] == 'a') {
                push(&stack, 'A');
                printStack(&stack);
            } else if (input[i] == 'b') {
                if (!isEmpty(&stack)) {
                    pop(&stack);
                    printStack(&stack);
                } else {
                    printStack(&stack);  // This will print "nil"
                }
            }
            i++;
        }

        if (isEmpty(&stack)) {
            printf("Aceito\n\n");
        } else {
            printf("Rejeito\n\n");
        }
    }

    return 0;
}
