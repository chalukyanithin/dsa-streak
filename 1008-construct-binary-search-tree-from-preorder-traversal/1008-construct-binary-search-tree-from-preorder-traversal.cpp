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
    unordered_map<int,int> mp;
    int i=0;
    TreeNode* BST(vector<int> preorder,int left,int right)
    {
        if(left>right) return NULL;
        int rootVal = preorder[i++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        root->left = BST(preorder,left,mid-1);
        root->right = BST(preorder,mid+1,right);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        return BST(preorder,0,preorder.size()-1);
    }
};