#include <unistd.h>

typedef struct Node {
    int value;
    int idx;
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

void StackPush(Stack* obj, int value, int idx) {
    if (obj == NULL) {
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = obj->top;
    new_node->idx = idx;
    obj->top = new_node;
}

void StackPop(Stack* obj) {
    obj->top = obj->top->next;
}

int StackTop(Stack* obj) {
    return obj->top->value;
}

int StackIdx(Stack *obj) {
    return obj->top->idx;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    Stack *stack = StackCreate();

    int *result = calloc(temperaturesSize, sizeof(int));
    StackPush(stack, -1, -1);

    for (int i = 0; i < temperaturesSize; i++) {
        while ((stack->top != NULL) && (temperatures[i] > StackTop(stack))) {
            int idx = StackIdx(stack);
            if (idx != -1) {
                result[StackIdx(stack)] = i - idx;
            }
            StackPop(stack);
        }

        StackPush(stack, temperatures[i], i);
    }

    *returnSize = temperaturesSize;
    free(stack);
    return result;
}
