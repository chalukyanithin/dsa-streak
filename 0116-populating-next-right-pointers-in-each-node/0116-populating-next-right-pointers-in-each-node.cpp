/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<Node*> nodes;
              int n=q.size();

            for(int i=0;i<n;i++)
            {
              Node* temp = q.front();
              nodes.push_back(temp);
              q.pop();
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
            }
            for(int i=0;i<nodes.size()-1;i++)
            {
                nodes[i]->next = nodes[i+1];
            }          
        }
        return root;
    }
};