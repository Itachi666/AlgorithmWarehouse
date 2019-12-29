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
    vector<int> ans;
    
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* r=q.front();
            q.pop();
            
            if (r==NULL)
                continue;
            
            ans.push_back(r->val);
            
            q.push(r->left);
            q.push(r->right);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        bfs(root1);
        bfs(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};