#include <unistd.h>

typedef struct Node {
    int value;
    int min_val;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *new_stack = malloc(sizeof(MinStack));
    new_stack->top = NULL;
    return new_stack;
}

void minStackPush(MinStack* obj, int value) {
    if (obj == NULL) {
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;

    if (obj->top == NULL) {
        new_node->min_val = value;
    } else {
        int curr_min = obj->top->min_val;
        new_node->min_val = (value < curr_min) ? value : curr_min;
    }
    
    new_node->next = obj->top;
    obj->top = new_node;
}

void minStackPop(MinStack* obj) {
    obj->top = obj->top->next;
}

int minStackTop(MinStack* obj) {
    return obj->top->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->top->min_val;
}

void minStackFree(MinStack* obj) {
    if (obj == NULL) {
        return;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/