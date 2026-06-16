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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val);
        }
        else {
            insert(root, val);
        }
        
        return root;
    }

    void insert(TreeNode* parent, int val) {

        if(val > parent->val) {
            if(parent->right) {
                insert(parent->right, val);
            }
            else  {
                parent->right = new TreeNode(val);
                return;
            }
        } else {
            if(parent->left) {
                insert(parent->left, val);
            }
            else {
                parent->left = new TreeNode(val);
                return;
            }
        }
    }
    
};