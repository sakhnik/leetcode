#include <numeric>
#include <vector>
#include <cstdint>

using namespace std;

// @leet start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::vector<int16_t> roots(edges.size() + 1);
        std::iota(roots.begin(), roots.end(), 0);
        std::vector<int16_t> sizes(edges.size() + 1, 1);

        auto getRoot = [&](int i, auto &&getRoot) -> int16_t {
            if (roots[i] == i) return i;
            return roots[i] = getRoot(roots[i], getRoot);
        };

        auto join = [&](int a, int b) {
            a = getRoot(a, getRoot);
            b = getRoot(b, getRoot);
            if (a == b)
                return false;
            if (sizes[a] < sizes[b]) {
                roots[a] = b;
                sizes[b] += sizes[a];
            } else {
                roots[b] = a;
                sizes[a] += sizes[b];
            }
            return true;
        };

        for (const auto &edge : edges) {
            if (!join(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};
// @leet end
