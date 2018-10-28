/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 other solution  former traversal root left right --> root right left then reserve
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack <TreeNode *> s;
        vector<int> res;
        if(root==nullptr) return res;
        TreeNode *top;
        TreeNode *pre=nullptr;
        s.push(root);
        while(!s.empty())
        {
            top=s.top();
            if(top!=nullptr&&( (top->left==nullptr&&top->right==nullptr)
                              || (pre!=nullptr&& (pre==top->left|| pre==top->right) ) ))
               {
                   res.push_back(top->val);
                   s.pop();
                   pre=top;
               }
               else
               {
                   if(top->right!=nullptr)
                   {
                       s.push(top->right);
                   }
                    if(top->left!=nullptr)
                   {
                       s.push(top->left);
                   }
               }
          }
               return res;
    }
};