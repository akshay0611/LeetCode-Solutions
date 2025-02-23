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
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int preIndex = 0, postIndex = 0;
    return build(pre, post, preIndex, postIndex);
  }

 private:
  TreeNode* build(vector<int>& pre, vector<int>& post, int& preIndex, int& postIndex) {
    TreeNode* root = new TreeNode(pre[preIndex++]);
    

    if (root->val != post[postIndex]) 
      root->left = build(pre, post, preIndex, postIndex);
    

    if (root->val != post[postIndex]) 
      root->right = build(pre, post, preIndex, postIndex);
    
    postIndex++; 
    return root;
  }
};
