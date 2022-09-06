#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node. */
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
    using MatT = vector<vector<int>>;

    MatT verticalTraversal(TreeNode* root) {

        std::map<int, std::map<int, std::vector<int>>> columns;
        int col{};
        int row{};

        auto traverse = [&](TreeNode *n, int row, int col, auto &&traverse) -> void {
            if (n->left)
                traverse(n->left, row + 1, col - 1, traverse);
            columns[col][row].push_back(n->val);

            if (n->right)
                traverse(n->right, row + 1, col + 1, traverse);
        };
        traverse(root, 0, 0, traverse);

        MatT ret;
        for (auto &col : columns)
        {
            std::vector<int> rows;
            for (auto &vals : col.second)
            {
                auto &v = vals.second;
                std::sort(v.begin(), v.end());
                rows.insert(rows.end(), v.begin(), v.end());
            }
            ret.emplace_back(std::move(rows));
        }
        return ret;
    }
};
