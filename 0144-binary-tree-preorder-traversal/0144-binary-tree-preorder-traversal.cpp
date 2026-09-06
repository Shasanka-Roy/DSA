class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Root
        result.push_back(root->val);

        // Left
        preorder(root->left);

        // Right
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};
