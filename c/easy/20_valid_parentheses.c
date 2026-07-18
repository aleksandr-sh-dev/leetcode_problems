#include <stdbool.h>

#define PARENTHESIS_OPEN  40 // ()
#define PARENTHESIS_CLOSE 41

#define SQUARE_BRACKET_OPEN  91 // []
#define SQUARE_BRACKET_CLOSE 93

#define BRACES_OPEN  123 // {}
#define BRACES_CLOSE 125

typedef enum {
    NOT_BRACKET,

    PARENTHESIS,
    SQUARE_BRACKET,
    BRACES,
} brackets_type_t;

bool is_opening(int symbol) {
    return ((symbol == PARENTHESIS_OPEN) || 
           (symbol == SQUARE_BRACKET_OPEN) || 
           (symbol == BRACES_OPEN)) ? true : false;
}

bool is_closing(int symbol) {
    return ((symbol == PARENTHESIS_CLOSE) || 
           (symbol == SQUARE_BRACKET_CLOSE) || 
           (symbol == BRACES_CLOSE)) ? true : false;
}

brackets_type_t get_brackets_type(int symbol) {
    switch(symbol) {
        case PARENTHESIS_OPEN:
        case PARENTHESIS_CLOSE:
            return PARENTHESIS;
        case SQUARE_BRACKET_OPEN:
        case SQUARE_BRACKET_CLOSE:
            return SQUARE_BRACKET;
        case BRACES_OPEN:
        case BRACES_CLOSE:
            return BRACES;
    }

    return NOT_BRACKET;
}

bool isValid(char* s) {
    int len = strlen(s);

    if (len == 1) {
        return false;
    }

    char *stack = malloc(sizeof(char) * len);
    int stack_ptr = -1;
    bool valid = true;

    for (int i = 0; i < len; i++) {
        if (is_opening((int)s[i])) {
            stack[++stack_ptr] = s[i];
        } else if (is_closing((int)s[i])) {
            // If we got closing bracket and nothing is on stack
            if(stack_ptr < 0) {
                free(stack);
                return false;
            }

            // Check brackets type match. If doesn't match
            if (get_brackets_type((int)stack[stack_ptr]) != get_brackets_type((int)s[i])) {
                free(stack);
                return false;
            } else {
                // Decrease stack pointer (pop the item)
                stack_ptr--;
            }
        }
    }

    // Items are left on the stack that means there were not enough closing brackets
    if (stack_ptr != -1) {
        valid = false;
    }

    free(stack);
    return valid;
}
