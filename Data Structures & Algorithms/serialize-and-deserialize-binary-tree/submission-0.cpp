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

class Codec {
public:

    // Serialize: Tree -> String
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "#";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Deserialize: String -> Tree
    TreeNode* deserialize(string data) {
        int pos = 0;
        return buildTree(data, pos);
    }

private:

    TreeNode* buildTree(string &data, int &pos) {
        // Find the next comma
        int comma = data.find(',', pos);

        string value;

        if (comma == string::npos) {
            value = data.substr(pos);
            pos = data.size();
        } else {
            value = data.substr(pos, comma - pos);
            pos = comma + 1;
        }

        // # represents NULL
        if (value == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(value));

        node->left = buildTree(data, pos);
        node->right = buildTree(data, pos);

        return node;
    }
};
