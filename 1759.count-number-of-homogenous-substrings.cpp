#include <string>

class Solution {
public:
    int countHomogenous(const std::string &s)
    {
        size_t res{0};

        int begin{0};

        auto accumulate = [&](int end) {
            size_t length = end - begin;
            res += length * (length + 1) >> 1;
            res &= 0xffffffffffull;
            begin = end;
        };

        for (int end = 1; end < s.size(); ++end)
        {
            if (s[begin] != s[end])
                accumulate(end);
        }
        accumulate(s.size());

        return res % 1000000007;
    }
};
