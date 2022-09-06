#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        std::priority_queue<int> fuel_pq;
        stations.push_back({target, std::numeric_limits<int>::max()});
        
        int res{};
        int prev_location{};
        for (const auto &station : stations)
        {
            startFuel -= station[0] - prev_location;
            while (!fuel_pq.empty() && startFuel < 0)
            {
                // Refuel on the biggest previous station so far
                startFuel += fuel_pq.top();
                fuel_pq.pop();
                ++res;
            }
            if (startFuel < 0)
                return -1;
            fuel_pq.push(station[1]);
            prev_location = station[0];
        }
        return res;
    }
};
