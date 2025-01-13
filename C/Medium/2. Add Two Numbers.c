/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverseList(struct ListNode** head)
{
    struct ListNode* prev = NULL;
    struct ListNode* current = *head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void push(struct ListNode** head, int data)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = data;
    newNode->next = (*head);
    (*head) = newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    struct ListNode summary;
    struct ListNode *head = &summary;
    head->next = NULL;

    int k = 0, j = 0, rest = 0;
    int max;

    int *list1 = (int*)malloc(sizeof(int) * 100);
    int *list2 = (int*)malloc(sizeof(int) * 100);

    if (l1->val == 0 && l2->val == 0) {
        if (l1->next == NULL && l2->next == NULL) {
            return l1;
        }
    }

    while (l1 != NULL) {
        list1[k] = l1->val;
        l1 = l1->next;
        k++;
    }

    while (l2 != NULL) {
        list2[j] = l2->val;
        l2 = l2->next;
        j++;
    }

    if (k > j) {
        max = k;
    }
    else {
        max = j;
    }

    for (int i = 0; i < max; i++) {
        if (list1[i] >= 0 && list2[i] >= 0) {
            int val = list1[i] + list2[i] + rest;
            if (val >= 10) {
                rest = val / 10;
                push(&head, (val % 10));
            }
            else {
                push(&head, (list1[i] + list2[i] + rest));
                rest = 0;
            }
        }
        else if (list1[i] < 0 && list2[i] >= 0) {
            int val = list2[i] + rest;
            if (val >= 10) {
                rest = val / 10;
                push(&head, (val % 10));
            }
            else {
                push(&head, val);
                rest = 0;
            }
        }
        else if (list1[i] >= 0 && list2[i] < 0) {
            int val = list1[i] + rest;
            if (val >= 10) {
                rest = val / 10;
                push(&head, (val % 10));
            }
            else {
                push(&head, val);
                rest = 0;
            }
        }
        else {
            continue;
        }
    }

    if (rest != 0) {
        push(&head, rest);
    }

    reverseList(&head);

    return summary.next;
}
