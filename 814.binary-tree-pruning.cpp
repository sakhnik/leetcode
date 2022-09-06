/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if (Prune(root))
        {
            //delete root;
            return nullptr;
        }
        return root;
    }

    bool Prune(TreeNode *n)
    {
        if (!n)
            return true;
        int left = Prune(n->left);
        if (left)
        {
            //delete n->left;
            n->left = nullptr;
        }
        int right = Prune(n->right);
        if (right)
        {
            //delete n->right;
            n->right = nullptr;
        }
        return left && right && n->val != 1;
    }
};
