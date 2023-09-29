class Solution {

bool isPossible(TreeNode* root, long long l, long long r){
    if(root == nullptr)  return true;
    
    if(root->val < r && root->val > l){
        return (isPossible(root->left,l,root->val) && isPossible(root->right,root->val,r));
    }else return false;
    
}

public:
    bool isValidBST(TreeNode* root) {
        long long int min = LONG_MIN, max = LONG_MAX;
        return isPossible(root, min, max);
    }
};

/*if(root->val < r and root->val > l)
        return isPossible(root->left, l, root->val) and 
                                isPossible(root->right, root->val, r);
    else return false;*/