#include <vector>

using namespace std;

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
    using VecT = std::vector<int>;
    VecT res;

    void Traverse(TreeNode *n)
    {
        if (!n)
            return;
        Traverse(n->left);
        res.push_back(n->val);
        Traverse(n->right);
    }

    VecT inorderTraversal(TreeNode* root)
    {
        Traverse(root);
        return res;
    }
};
