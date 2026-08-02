#include <unistd.h>

#define MULTIPLICATION "*"
#define DIVISION       "/"
#define ADDITION       "+"
#define SUBSTRACTION   "-"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack* StackCreate(void) {
    Stack *new_stack = malloc(sizeof(Stack));
    new_stack->top = NULL;
    return new_stack;
}

void StackPush(Stack* obj, int value) {
    if (obj == NULL) {
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = obj->top;
    obj->top = new_node;
}

void StackPop(Stack* obj) {
    obj->top = obj->top->next;
}

int StackTop(Stack* obj) {
    return obj->top->value;
}

int evalRPN(char** tokens, int tokensSize) {
    Stack *stack = NULL;

    stack = StackCreate();

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], MULTIPLICATION) == 0) {
            int val1 = StackTop(stack);
            StackPop(stack);
            int val2 = StackTop(stack);
            StackPop(stack);
            int res = val2 * val1;
            StackPush(stack, res);
        } else if (strcmp(tokens[i], DIVISION) == 0) {
            int val1 = StackTop(stack);
            StackPop(stack);
            int val2 = StackTop(stack);
            StackPop(stack);
            int res = val2 / val1;
            StackPush(stack, res);
        } else if (strcmp(tokens[i], ADDITION) == 0) {
            int val1 = StackTop(stack);
            StackPop(stack);
            int val2 = StackTop(stack);
            StackPop(stack);
            int res = val2 + val1;
            StackPush(stack, res);
        } else if (strcmp(tokens[i], SUBSTRACTION) == 0) {
            int val1 = StackTop(stack);
            StackPop(stack);
            int val2 = StackTop(stack);
            StackPop(stack);
            int res = val2 - val1;
            StackPush(stack, res);
        } else {
            int num = atoi(tokens[i]);
            StackPush(stack, num);
        }
    }

    int result = StackTop(stack);
    StackPop(stack);
    free(stack);

    return result;
}
