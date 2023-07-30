class Solution {
public:

    int res=1, r=0;
    int maxi=0;
    bool isCompleteTree(TreeNode* root) {
        nroflevels(root,0);
        recursive(root,0);
        return res==0 ? false : true;
    }
    void nroflevels(TreeNode * root,int cnt)
    {
        if(root->left)
        {
            nroflevels(root->left,cnt+1);
        }
        maxi=max(cnt,maxi);
        if(root->right)
        {
            nroflevels(root->right,cnt+1);
        }
        maxi=max(cnt,maxi);
    }
    void recursive(TreeNode * root,int currlevel)
    {
        if(root->left)
        {
            recursive(root->left,currlevel+1);
        }
        if((!root->left || !root->right) && currlevel<maxi-1)
        {
            res=0;
        }
        if(r==1 && (root->left || root->right) && currlevel==maxi-1)
        {
            res=0;
        }
        if(root->right && !root->left)
        {
            res=0;
        }
        if(((root->left && !root->right) || (!root->left && !root->right)) && currlevel==maxi-1)
        {
            r=1;
        }
        if(root->right)
        {
            recursive(root->right,currlevel+1);
        }
    }
};