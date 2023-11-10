#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs)
    {
        // Collect the neighbours for lookups
        std::unordered_map<int, std::vector<int>> neighbours;
        for (const auto &p : adjacentPairs)
        {
            neighbours[p[0]].push_back(p[1]);
            neighbours[p[1]].push_back(p[0]);
        }

        // Find an end: just one neighbour
        auto it = std::find_if(neighbours.begin(), neighbours.end(),
                [](auto &n) { return n.second.size() == 1; });

        // Collect the chain by going through the neighbours
        std::vector<int> res;
        res.reserve(adjacentPairs.size() + 1);
        do
        {
            int num = it->first;
            int next = it->second[0];
            if (res.size() > 0 && next == res.back())
                next = it->second[1];
            res.push_back(num);
            it = neighbours.find(next);
        }
        while (it->second.size() > 1);
        res.push_back(it->first);
        return res;
    }
};
