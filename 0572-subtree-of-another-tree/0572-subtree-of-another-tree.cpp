/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* tree1, TreeNode* tree2){
        if(!tree1 && !tree2)
        return true;
        if(!tree1 || !tree2)
        return false;

        if(tree1->val!=tree2->val)
        return false;

        bool left = check(tree1->left,tree2->left);
        bool right = check(tree1->right,tree2->right);

        if(left && right)
        return true;
        else 
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
        return false;

        if(root->val == subRoot->val){
        bool ans = check(root,subRoot);
        if(ans)
        return ans;
        }

        
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        if(left || right)
        return true;
        else
        return false;
    
        
        
    }
};