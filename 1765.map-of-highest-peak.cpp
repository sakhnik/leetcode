#include <vector>
#include <queue>

using namespace std;

// @leet start
class Solution {
public:
    using MapT = vector<vector<int>>;

    struct Pos
    {
        int row, col;
    };

    MapT highestPeak(MapT &isWater) {
        int height = isWater.size();
        auto width = isWater[0].size();

        std::queue<Pos> q;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (isWater[i][j]) {
                    q.push({i, j});
                }
                --isWater[i][j];
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            auto mark = [&](int row, int col) {
                if (row < 0 || row >= height || col < 0 || col >= width)
                    return;
                if (isWater[row][col] >= 0)
                    return;
                isWater[row][col] = isWater[p.row][p.col] + 1;
                q.push({row, col});
            };
            mark(p.row - 1, p.col);
            mark(p.row + 1, p.col);
            mark(p.row, p.col - 1);
            mark(p.row, p.col + 1);
        }

        return isWater;
    }
};
// @leet end
