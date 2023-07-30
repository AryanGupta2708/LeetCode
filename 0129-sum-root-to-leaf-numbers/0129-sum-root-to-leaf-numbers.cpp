class Solution 
{
public:
    int sum = 0; 
    int sumNumbers(TreeNode* root) 
    {
        DFS(root, "");
        return sum;
    }

    void DFS(TreeNode* root, string s)
    {
        if(!root)
            return;
        
        s += to_string(root -> val);

        if(!root -> left && !root -> right)
            sum += stoi(s);
        
        DFS(root->left, s);
        DFS(root->right, s);
    }
};