/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;

        while(temp){
            temp=temp->next;
            count++;
        }

        temp = head;

        
        
        if(n==count){
            head = head->next;
            return head;
        }

        if(n==1){
            while(temp->next->next){
            temp=temp->next;
            }
            temp->next = nullptr;
            return head;

        }

        

        n = count - n + 1;
        int i=0;

        while(i!=n-2){
            i++;
            temp=temp->next;
        }

        temp->next = temp->next->next;

        return head;

        
        
    }
};