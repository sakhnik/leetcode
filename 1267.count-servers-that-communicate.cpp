#include <vector>
#include <array>
#include <cstdint>

using namespace std;

// @leet start
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        std::array<uint8_t, 250> rows{}, columns{}, last_in_row{};
        int count{};
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                uint8_t computer = grid[i][j];
                rows[i] += computer;
                columns[j] += computer;
                count += computer;
                if (computer) {
                    last_in_row[i] = j;
                }
            }
        }

        for (int i = 0; i < height; ++i) {
            if (rows[i] == 1) {
                int j = last_in_row[i];
                if (grid[i][j] && columns[j] == 1)
                    --count;
            }
        }
        return count;
    }
};
// @leet end
