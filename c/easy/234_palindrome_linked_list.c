#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // Find middle node
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;
    struct ListNode* next;

    // Reverse
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Check if list is palindrome
    while(prev != NULL) {
        if (prev->val != head->val) {
            return false;
        }
        prev = prev->next;
        head = head->next;
    }

    return true;
}
