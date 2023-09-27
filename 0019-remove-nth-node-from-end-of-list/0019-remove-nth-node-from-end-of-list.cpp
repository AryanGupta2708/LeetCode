class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
		// move fast pointer to the n + 1 element
        while (n--) { fast = fast->next; }
        
        // handle edge case: given n is always valid, 
        // if fast reached the end, we need to remove the first element
        if (fast == nullptr) return head->next;

        // move both pointers at the same time maintaing the difference
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow will be pointing to the element before the one we want to remove
        slow->next = slow->next->next;
        
        return head;
    }
};