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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result{};
        recursePreorder(root, result);
        return result;
    }

    void recursePreorder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;
        res.emplace_back(root->val);
        recursePreorder(root->left, res);
        recursePreorder(root->right, res);
    }
};