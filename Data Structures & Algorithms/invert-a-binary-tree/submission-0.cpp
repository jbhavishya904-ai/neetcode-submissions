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
    TreeNode* invertTree(TreeNode* root) {
        // If the tree is empty, return nullptr
        if (root == nullptr)
            return nullptr;

        // Swap left and right children
        swap(root->left, root->right);

        // Invert the left subtree
        invertTree(root->left);

        // Invert the right subtree
        invertTree(root->right);

        return root;
    }
};
