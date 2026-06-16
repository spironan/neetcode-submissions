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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result{};
        
        recurseInOrder(root, result);

        return result;
    }

    void recurseInOrder(TreeNode* root, vector<int>& res) {
        
        if(root == nullptr)
            return;

        recurseInOrder(root->left, res);
        res.emplace_back(root->val);
        recurseInOrder(root->right, res);
    }
};