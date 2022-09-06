#define TEST

#include <algorithm>
#include <limits>

#ifdef TEST
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#endif

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
    int count{};

    void Traverse(int max_val, TreeNode *n)
    {
        if (!n)
            return;
        count += n->val >= max_val;
        auto new_max_val = std::max(max_val, n->val);
        Traverse(new_max_val, n->left);
        Traverse(new_max_val, n->right);
    }

    int goodNodes(TreeNode* root) {
        Traverse(std::numeric_limits<int>::max(), root);        
        return count;
    }
};
