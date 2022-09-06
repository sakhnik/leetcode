#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    using LevelsT = vector<vector<int>>;

    LevelsT levelOrder(Node* root) {
        LevelsT res;
        if (!root)
            return res;

        auto dfs = [&](Node *n, int level, auto &&dfs) -> void {
            if (res.size() <= level)
                res.emplace_back();
            res[level].push_back(n->val);

            for (Node *ch : n->children)
                dfs(ch, level + 1, dfs);
        };
        dfs(root, 0, dfs);
        return res;
    }
};
