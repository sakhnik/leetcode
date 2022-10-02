#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    std::unordered_map<int, int> memo;

    int GetKey(bool buying, int t, int day)
    {
        return 10000000 * buying + t * 1001 + day;
    }

    int maxProfit(int k, vector<int>& prices) {

        auto profit = [&](bool buying, int t, int day, auto &&profit) -> int {
            if (!t || day >= prices.size())
                return 0;
            auto key = GetKey(buying, t, day);
            auto it = memo.find(key);
            if (it != memo.end())
                return it->second;

            if (buying)
            {
                return memo[key] = std::max(-prices[day] + profit(false, t, day + 1, profit), profit(true, t, day + 1, profit));
            }
            else
            {
                return memo[key] = std::max(prices[day] + profit(true, t - 1, day + 1, profit), profit(false, t, day + 1, profit));
            }
        };
        return profit(true, k, 0, profit);
    }
};
