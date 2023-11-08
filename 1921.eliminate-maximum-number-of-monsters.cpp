#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed)
    {
        for (int i = 0; i < dist.size(); ++i)
            dist[i] = std::ceil(static_cast<double>(dist[i]) / speed[i]);
        std::sort(dist.begin(), dist.end());
        for (int i = 0; i < dist.size(); ++i)
        {
            if (i && dist[i] <= i)
                return i;
        }
        return dist.size();
    }
};
