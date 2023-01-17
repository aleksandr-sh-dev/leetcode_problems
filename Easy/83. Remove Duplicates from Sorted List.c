struct ListNode* deleteDuplicates(struct ListNode *head)
{
    if(head == NULL) return NULL;

    struct ListNode *current = head;
    struct ListNode *nextnode;

    while (current->next != 0) { 
        if (current->val == current->next->val) {
            nextnode = current->next->next;
            free(current->next);
            current->next = nextnode;
        }
        else {
            current = current->next;
        }
    }

    return head;
}
