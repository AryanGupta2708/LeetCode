class Solution {
public:

    TreeNode* createTree(int index,int len){

        if(index >= len) return NULL;

        TreeNode* head = new TreeNode(-1);

        head->left  =createTree(2*index + 1,len);
        head->right = createTree(2*index + 2,len);

        return head;

    }
    void buildTree(ListNode* &head,TreeNode* &tree){

        if(!head) return ;
        if(!tree) return ;

        buildTree(head,tree->left);
        tree->val = head->val;
        head = head->next;
        buildTree(head,tree->right);

    }

    TreeNode* sortedListToBST(ListNode* head) {

        int len = 0;
        ListNode* ptr = head;
        while(ptr){
            len++;
            ptr = ptr->next;
        }

        TreeNode* tree = createTree(0,len);

        buildTree(head,tree);

        return tree;
    }
};