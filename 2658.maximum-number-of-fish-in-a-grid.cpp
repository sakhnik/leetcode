#include <vector>
#include <iostream>

using namespace std;

// @leet start
class Solution {
public:
    using GridT = vector<vector<int>>;

    int findMaxFish(GridT &grid) {
        int height = grid.size();
        int width = grid[0].size();

        auto dfs = [&](int row, int col, auto &&dfs) -> int {
            if (row < 0 || row >= height || col < 0 || col >= width) {
                return 0;
            }
            int fish = grid[row][col];
            if (!fish) {
                return 0;
            }
            grid[row][col] = 0;
            return fish + dfs(row, col + 1, dfs) + dfs(row, col - 1, dfs) + dfs(row + 1, col, dfs) + dfs(row - 1, col, dfs);
        };

        int res{};
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                res = std::max(res, dfs(row, col, dfs));
            }
        }
        return res;
    }
};
// @leet end

int main()
{
    Solution::GridT grid{{4, 5, 5}, {0, 10, 0}};
    std::cout << Solution{}.findMaxFish(grid);
}
