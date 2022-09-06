#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int CountMatch(int i, const std::string &stamp, const std::string &target)
    {
        int count{};
        for (int j = 0; j < stamp.size(); ++j)
        {
            if (stamp[j] != target[i + j])
            {
                if (target[i + j] != '.')
                    return false;
            }
            else
            {
                ++count;
            }
        }
        return count;
    }

    int FindMatch(const std::string &stamp, const std::string &target)
    {
        for (int i = 0, n = target.size() - stamp.size(); i <= n; ++i)
        {
            if (CountMatch(i, stamp, target))
                return i;
        }
        return -1;
    }

    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> res;

        for (int chars_left = target.size(); chars_left > 0; )
        {
            auto idx = FindMatch(stamp, target);
            if (idx == -1)
                return {};
            res.push_back(idx);
            for (int i = 0; i < stamp.size(); ++i)
            {
                if (target[idx + i] != '.')
                {
                    --chars_left;
                    target[idx + i] = '.';
                }
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

#ifdef TEST
int main()
{
    auto res = Solution{}.movesToStamp("abc", "ababc");
    assert(res.size() == 2);

    res = Solution{}.movesToStamp("abca", "aabcaca");
    assert(res.size() == 3);
    return 0;
}
#endif
