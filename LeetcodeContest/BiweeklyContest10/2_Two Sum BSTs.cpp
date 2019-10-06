/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ans=false;
    
    bool searchInTree(TreeNode* root, int val) {
        if (root->val==val)
            return true;
        
        if (root->val<val && root->right!=NULL)
            return searchInTree(root->right, val);
        
        if (root->val>val && root->left!=NULL)
            return searchInTree(root->left, val);
        
        return false;
    }
    
    void dfs(TreeNode* node, TreeNode* root2, int t) {
        if (ans)
            return;
        
        if (node==NULL)
            return;
        
        //cout<<node->val<<endl;
        
        ans=searchInTree(root2, t-node->val);
        
        dfs(node->left, root2, t);
        dfs(node->right, root2, t);
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        dfs(root1, root2, target);
        
        
        return ans;
    }
};