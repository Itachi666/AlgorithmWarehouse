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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> deep;
        if (root==NULL)
            return 0;
        int ans=0, d=0;
        
        q.push(root);
        deep.push(0);
        
        while (!q.empty()) {
            TreeNode* r=q.front();
            int de=deep.front();
            deep.pop();
            q.pop();
            
            // cout<<r->val<<' '<<de<<endl;
            
            if (de==d)
                ans+=r->val;
            else {
                ans=r->val;
                d=de;
            }
            
            if (r->left!=NULL) {
                q.push(r->left);
                deep.push(de+1);
            }
            if (r->right!=NULL) {
                q.push(r->right);
                deep.push(de+1);
            }
        }
        
        return ans;
    }
};