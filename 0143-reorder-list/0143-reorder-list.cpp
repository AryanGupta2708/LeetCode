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
vector<int> storeToVector(ListNode* head)
{
    vector<int> v;
        ListNode* temp = head;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        return v;
}
    void reorderList(ListNode* head) {
         
        vector<int>v=storeToVector(head);
        int first=0;
        int last=v.size()-1;
        ListNode* temp = head;
        int count=0;
        while(temp)
        {
            if(count%2==0)
            {
                temp->val=v[first];
                first++;
            }
            else{
                temp->val=v[last];
                last--;
            }
            count++;
            temp=temp->next;
        }
    }
};