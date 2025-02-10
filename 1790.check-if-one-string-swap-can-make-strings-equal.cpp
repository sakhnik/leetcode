#include <string>
#include <cassert>

using namespace std;

// @leet start
class Solution {
public:
    bool areAlmostEqual(const string &s1, const std::string &s2) {
        int count{};
        int first = -1;
        int last = -1;
        assert(s1.size() == s2.size());
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i])
                continue;
            if (first < 0)
                first = i;
            last = i;
            ++count;
        }
        return count == 0 || (count == 2 && s1[first] == s2[last] && s1[last] == s2[first]);
    }
};
// @leet end
