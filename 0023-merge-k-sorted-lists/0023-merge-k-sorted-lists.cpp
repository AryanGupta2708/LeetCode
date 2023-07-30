class Solution {
private:
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *lst, *node, *curr_lst;
		curr_lst = lst = node = nullptr;
		
		while ( (node=getNextLowest(lists)) ){
			if (!lst){
				lst = curr_lst = node;
			} else {
				curr_lst->next = node;
				curr_lst = curr_lst->next;
			}
		}
		if (curr_lst)
			curr_lst->next = nullptr;
		
		return lst;
	}

	ListNode* getNextLowest(vector<ListNode*>& lists){
		int curr_lowest = INT_MAX, curr_idx = -1;
		for (int i = 0; i < lists.size(); i++){
			for (ListNode* cursor = lists[i]; cursor; cursor = cursor->next){
				if (cursor->val < curr_lowest){
					curr_idx = i;
					curr_lowest = cursor->val;
					break;
				}
			}
		}

		if (curr_idx != -1){
			ListNode* res = lists[curr_idx];
			lists[curr_idx] = lists[curr_idx]->next;
			return res;
		}
		return nullptr;
	}
};