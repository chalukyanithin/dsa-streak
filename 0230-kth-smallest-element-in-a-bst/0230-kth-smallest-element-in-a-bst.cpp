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
     int ans;
     void elements(TreeNode* root,int& c)
    {
        if(root==NULL) return;
        elements(root->left,c);
        c--;
        if(c==0)
        {
            ans=root->val;
            return;
        }
        elements(root->right,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        elements(root,k);
        return ans;
    }
};