#include <vector>
#include <limits>
#include <cstdint>

using namespace std;

// @leet start
class Solution {
public:
    int mostProfitablePath(const vector<vector<int>>& edges, int bob, const vector<int>& amount) {
        const int n = amount.size();
        std::vector<std::vector<int>> adj(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        std::vector<int> bobPath(n, std::numeric_limits<int>::max());
        std::vector<uint8_t> visited(n, false);
        auto findBob = [&](int node, auto &&findBob) -> int {
            visited[node] = true;
            if (node == bob) {
                visited[node] = false;
                return bobPath[node] = 0;
            }
            for (auto n : adj[node]) {
                if (!visited[n]) {
                    auto t = findBob(n, findBob);
                    if (t != -1) {
                        visited[node] = false;
                        return bobPath[node] = t + 1;
                    }
                }
            }
            visited[node] = false;
            return -1;
        };
        findBob(0, findBob);
 
        int max_income = std::numeric_limits<int>::min();
        auto findAlice = [&](int node, int t, int income, auto &&findAlice) -> void {
            visited[node] = true;
            auto p = bobPath[node];
            if (p > t) {
                income += amount[node];
            } else if (p == t) {
                income += amount[node] / 2;
            }

            if (node && adj[node].size() == 1) {
                max_income = std::max(income, max_income);
            }

            for (auto n : adj[node]) {
                if (!visited[n]) {
                    findAlice(n, t + 1, income, findAlice);
                }
            }
            visited[node] = false;
        };
        findAlice(0, 0, 0, findAlice);

        return max_income;
    }
};
// @leet end

int main()
{
    Solution{}.mostProfitablePath({{0,1},{1,2},{1,3},{3,4}}, 3, {-2,4,2,-4,6});
    //Solution{}.mostProfitablePath({{0,1},{1,2},{2,3}}, 3, {-5644,-6018,1188,-8502});
    //Solution{}.mostProfitablePath({{0,2},{0,5},{1,3},{1,5},{2,4}}, 4, {5018,8388,6224,3466,3808,3456});
	
    return 0;
}
