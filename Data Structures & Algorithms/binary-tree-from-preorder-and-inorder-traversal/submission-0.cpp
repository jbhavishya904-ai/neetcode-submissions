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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        // Store index of each value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return solve(preorder, inorder, 0, inorder.size() - 1, preIndex, mp);
    }

private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int left, int right, int& preIndex,
                    unordered_map<int, int>& mp) {

        if (left > right)
            return nullptr;

        // First element in preorder is the root
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = mp[rootValue];

        // Build left subtree
        root->left = solve(preorder, inorder, left, mid - 1,
                           preIndex, mp);

        // Build right subtree
        root->right = solve(preorder, inorder, mid + 1, right,
                            preIndex, mp);

        return root;
    }
};
