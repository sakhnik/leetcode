#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        std::vector<int> islands(width * height + 1);
        std::iota(islands.begin(), islands.end(), 0);
        std::vector<int> sizes(islands.size(), 0);

        auto getIslandImpl = [&](int i, auto &&getIsland) {
            auto &is = islands[i];
            if (i == is)
                return i;
            return is = getIsland(is, getIsland);
        };

        auto getIsland = [&](int i) { return getIslandImpl(i, getIslandImpl); };

        auto join = [&](int i, int j) {
            auto isi = getIsland(i);
            auto isj = getIsland(j);
            if (isi == isj)
                return;
            if (sizes[isi] < sizes[isj]) {
                islands[isi] = isj;
                sizes[isj] += sizes[isi];
            } else {
                islands[isj] = isi;
                sizes[isi] += sizes[isj];
            }
        };

        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                auto i = r * width + c;
                if (grid[r][c]) {
                    sizes[i] = 1;
                    if (c > 0 && grid[r][c - 1]) {
                        join(i - 1, i);
                    }
                    if (r > 0 && grid[r - 1][c]) {
                        join(i - width, i);
                    }
                }
            }
        }

        auto checkIsland = [&](int r, int c) -> int {
            if (r < 0 || r >= height || c < 0 || c >= width)
                return islands.size() - 1;
            return getIsland(r * width + c);
        };

        int max = *std::max_element(sizes.begin(), sizes.end());
        std::vector<int> neighbours;
        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                if (grid[r][c])
                    continue;
                auto i = r * width + c;
                neighbours.clear();
                neighbours.push_back(checkIsland(r - 1, c));
                neighbours.push_back(checkIsland(r + 1, c));
                neighbours.push_back(checkIsland(r, c - 1));
                neighbours.push_back(checkIsland(r, c + 1));
                std::sort(neighbours.begin(), neighbours.end());
                neighbours.erase(std::unique(neighbours.begin(), neighbours.end()), neighbours.end());
                auto size = 1 + std::accumulate(neighbours.begin(), neighbours.end(), 0,
                        [&](int a, int i) {
                            return a + sizes[i];
                        });
                if (size > max)
                    max = size;
            }
        }

        return max;
    }
};
// @leet end
