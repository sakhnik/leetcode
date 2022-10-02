#include <string>

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
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        auto s = std::to_string(root->val);
        auto sl = tree2str(root->left);
        auto sr = tree2str(root->right);
        if (sr.empty())
            return sl.empty() ? s : s + "(" + std::move(sl) + ")";
        return s + "(" + std::move(sl) + ")(" + std::move(sr) + ")";
    }
};
