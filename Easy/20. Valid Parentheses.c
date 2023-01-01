typedef struct stack {
    int max;
    int top;
    char *item;
} stack_t;

static stack_t *init_stack(int max);
static void pop_stack(stack_t *stack);
static void push_stack(char s, stack_t *stack);
static bool is_full_stack(stack_t *stack);
static bool is_empty_stack (stack_t *stack);
static void destroy_stack(stack_t *stack);

stack_t *init_stack(int max)
{
    stack_t *stack = (stack_t *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->max = max;
    stack->item = (char *)malloc(max * sizeof(char));

    return stack;
}

void destroy_stack(stack_t *stack)
{
    free(stack->item);
    free(stack);
    stack = NULL;
}

void pop_stack(stack_t *stack) {

    if (is_empty_stack(stack)) {
        printf("Stack empty!\n");
        abort();
    }
   
    // strcpy(data, stack->item[stack->top]);
    stack->top--;
}

void push_stack(char s, stack_t *stack)
{
    if (is_full_stack(stack)) {
        printf("Stack if full!\n");
        abort();
    }

    stack->top++;
    stack->item[stack->top] = s;
}

bool is_empty_stack (stack_t *stack)
{
    return (stack->top == -1);
}

bool is_full_stack(stack_t *stack)
{
    return (stack->top == (stack->max - 1));
}

bool isValid(char *s)
{
    bool result = true;
    int lenght = strlen(s);
    // char data[80];

    stack_t *stack = init_stack(lenght);

    if (s[0] == ')') return false;
    if (s[0] == ']') return false;
    if (s[0] == '}') return false;
    if (strlen(s) == 1) return false;

    for (int i = 0; i < lenght; i++) {
        switch (s[i]) {
            case '(':
                push_stack(s[i], stack);
                break; 
            case '[':
                push_stack(s[i], stack);
                break;
            case '{':
                push_stack(s[i], stack);
                break;

            case ')':
                if (is_empty_stack(stack) || stack->item[stack->top] != '(') {
                    destroy_stack(stack);
                    return false;
                }
                pop_stack(stack);
                break;
            case ']':
                if (is_empty_stack(stack) || stack->item[stack->top] != '[') {
                    destroy_stack(stack);
                    return false;
                }
                pop_stack(stack);
                break;
            case '}':
                if (is_empty_stack(stack) || stack->item[stack->top] != '{') {
                    destroy_stack(stack);
                    return false;
                }
                pop_stack(stack);
                break;
        }
    }
    
    return is_empty_stack(stack);
}
