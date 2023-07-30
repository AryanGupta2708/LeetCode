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
    void createMapping(vector<int> & inorder , map<int,int>& nodeToIndex , int n) {
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int& pointer , int start , int end ,int n, map<int,int>& nodeToIndex) {
        if(pointer<0 || start>end) {
            return NULL;
        }
        
        int element = postorder[pointer--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder , postorder , pointer , position+1 , end , n , nodeToIndex);
        root->left = solve(inorder , postorder , pointer , start , position-1 , n , nodeToIndex );
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int pointer = n-1;
        map<int,int> nodeToIndex;
        createMapping(inorder , nodeToIndex , n);
        TreeNode* node = solve(inorder , postorder , pointer , 0 , n-1 , n , nodeToIndex);
        return node;
    }
};