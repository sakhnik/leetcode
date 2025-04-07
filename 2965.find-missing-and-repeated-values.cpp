#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //int w = grid.size(), n = w * w, duplicate = 0;

        //// Cycle sort-like approach to place numbers correctly
        //for (int i = 0; i < n; ++i) {
        //    int &val = grid[i / w][i % w];
        //    while (val && val != i + 1) {
        //        int &target = grid[(val - 1) / w][(val - 1) % w];
        //        if (target == val) {
        //            duplicate = val;
        //            val = 0;
        //            break;
        //        }
        //        swap(val, target);
        //    }
        //}

        //for (int i = 0; i < n; ++i) {
        //    if (!grid[i / w][i % w]) {
        //        return {duplicate, i + 1};
        //    }
        //}

        //return {};

        int64_t sum = 0, sqrSum = 0;
        int64_t n = grid.size();
        int64_t total = n * n;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int64_t a = grid[row][col];
                sum += a;
                sqrSum += a * a;
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        int64_t sumDiff = sum - total * (total + 1) / 2;
        int64_t sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = x² - y²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};
// @leet end

int main()
{
    std::vector<std::vector<int>> grid = {{9,1,7}, {8,9,2}, {3,4,6}};
    Solution{}.findMissingAndRepeatedValues(grid);
}
