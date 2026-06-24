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
    bool issym(TreeNode* rootR,TreeNode* rootL)
    {
        if(rootR==NULL and rootL==NULL) return true;
        else if(rootR==NULL or rootL==NULL) return false;

        return (rootR->val==rootL->val and issym(rootR->left,rootL->right) and 
                                issym(rootR->right,rootL->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return issym(root->left,root->right);
    }
};