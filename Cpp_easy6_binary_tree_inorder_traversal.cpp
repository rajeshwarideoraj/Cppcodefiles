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
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }

private:
    void inorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorderTraversalHelper(node->left, result);

        // Visit the current node
        result.push_back(node->val);

        // Traverse the right subtree
        inorderTraversalHelper(node->right, result);
    }
};