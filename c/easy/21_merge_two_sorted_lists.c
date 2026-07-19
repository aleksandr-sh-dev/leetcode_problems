#include <stddef.h>

#define SOLUTION_RECURSION    (1)
#define SOLUTION_TWO_POINTERS (2)

#define SOLUTION SOLUTION_RECURSION

struct ListNode {
    int val;
    struct ListNode *next;
};

#if SOLUTION == SOLUTION_RECURSION
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list2 == NULL) {
        return list1;
    }
    if (list1 == NULL) {
        return list2;
    }

    if (list1->val <= list2->val) {
        struct ListNode *rest = mergeTwoLists(list1->next, list2);
        list1->next = rest;
        return list1;
    } else {
        struct ListNode *rest = mergeTwoLists(list1, list2->next);
        list2->next = rest;
        return list2;
    }
}
#endif // SOLUTION_RECURSION

#if SOLUTION == SOLUTION_TWO_POINTERS
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode merged;
    struct ListNode *head = &merged;

    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    while(list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        else {
            head->next = list2;
            list2 = list2->next;
            head = head->next;
        }
    }

    if (list1 != NULL) {
        head->next = list1;
    }
    if (list2 != NULL) {
        head->next = list2;
    }

    return merged.next;
}
#endif // SOLUTION_TWO_POINTERS
