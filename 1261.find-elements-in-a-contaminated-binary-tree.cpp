#include <memory>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() { delete(left); delete(right); }
};

// @leet start
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
class FindElements {
public:
    TreeNode *root;

    FindElements(TreeNode* root)
        : root{root}
    {
        //auto recover = [](int x, TreeNode *n, auto &&recover) -> void {
        //    if (n) {
        //        n->val = x;
        //        recover(2 * x + 1, n->left, recover);
        //        recover(2 * x + 2, n->right, recover);
        //    }
        //};
        //recover(0, root, recover);
    }
    
    bool find(int target) {
        auto f = [this](int x, auto &&f) -> TreeNode* {
            if (!x) {
                return root;
            }
            if (auto p = f((x - 1) / 2, f)) {
                return (x - 1) % 2 ? p->right : p->left;
            }
            return nullptr;
        };
        return f(target, f) != nullptr;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @leet end

int main()
{
    auto root = std::unique_ptr<TreeNode>(new TreeNode(-1, nullptr, new TreeNode(-1)));
    FindElements s(root.get());
    std::cout << s.find(1) << std::endl;
    std::cout << s.find(2) << std::endl;
    return 0;
}
