#include <vector>
#include <unordered_map>

using namespace std;

// @leet start
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        std::unordered_map<int, int> colors;
        std::unordered_map<int, int> balls;
        for (const auto &q : queries) {
            auto ball_it = balls.find(q[0]);
            if (ball_it != balls.end()) {
                int old_color = ball_it->second;
                auto it = colors.find(old_color);
                if (!--it->second) {
                    colors.erase(it);
                }
            }
            balls[q[0]] = q[1];
            ++colors[q[1]];
            res.push_back(colors.size());
        }
        
        return res;
    }
};
// @leet end
