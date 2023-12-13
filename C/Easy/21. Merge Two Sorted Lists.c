/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

