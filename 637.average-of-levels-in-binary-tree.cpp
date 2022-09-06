#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    vector<double> v;
    vector<int> counts;

    void Traverse(int level, TreeNode *n)
    {
        if (!n)
            return;

        if (level >= counts.size())
        {
            counts.push_back(0);
            v.push_back(0.);
        }
        int &count = counts[level];
        double &av = v[level];
        av = (av * count + n->val) / (count + 1);
        ++count;
        Traverse(level + 1, n->left);
        Traverse(level + 1, n->right);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        Traverse(0, root);
        return v;
    }
};
