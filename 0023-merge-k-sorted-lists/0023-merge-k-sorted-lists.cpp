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

    

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()){
        return nullptr;}

        ListNode* nn = nullptr;

        for(int i=0;i<lists.size();i++){
            nn = mergethem(nn,lists[i]);
        }

        return nn;
        
    }

    ListNode* mergethem(ListNode* l1, ListNode* l2){
        if(l1==nullptr)
        return l2;

        if(l2==nullptr)
        return l1;

        if(l1->val<=l2->val){
            l1->next = mergethem(l1->next,l2);
            return l1;
        }

        else{
            l2->next = mergethem(l2->next,l1);
            return l2;
        }
    }
};