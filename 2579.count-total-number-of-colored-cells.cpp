// @leet start
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (n > 1 ? 2ll * n * (n - 1) : 0);
    }
};
// @leet end
