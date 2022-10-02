#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        std::sort(properties.begin(), properties.end(),
                [](auto &a, auto &b) {
                    if (a[0] > b[0])
                        return true;
                    return a[0] == b[0] && a[1] < b[1];
                });
        int count{};
        int max_defence{properties[0][1]};
        for (int i = 1; i < properties.size(); ++i)
        {
            if (properties[i][1] < max_defence)
                ++count;
            else
                max_defence = properties[i][1];
        }
        return count;
    }
};
