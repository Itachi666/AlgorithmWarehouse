/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> value;
    
    void dfs(TreeNode* root, int t) {
        if (root==NULL)
            return;
        root->val=t;
        value.insert(t);
        
        dfs(root->left, t*2+1);
        dfs(root->right, t*2+2);
    }
    
    FindElements(TreeNode* root) {
        if (root==NULL)
            return;
        root->val=0;
        value.insert(0);
        
        dfs(root->left, root->val*2+1);
        dfs(root->right, root->val*2+2);
    }
    
    bool find(int target) {
        return (value.find(target)!=value.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */