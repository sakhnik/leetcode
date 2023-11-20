#include <string>
#include <unordered_set>
#include <array>

class Solution {
public:
    int countPalindromicSubsequence(const std::string &s) {
        int res{};

        // Custom hash table for different middle characters
        constexpr int CHAR_COUNT = 'z' - 'a' + 1;
        std::array<bool, 'z' + 1> mids;
        mids.fill(false);
        int mids_count{};

        // For any character that can be at the beginning and the end of a palindrome
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            auto first = s.find(ch);
            if (first == s.npos)
                continue;
            auto last = s.rfind(ch);
            // Count the possible middle characters
            mids.fill(false);
            mids_count = 0;
            for (size_t i = first + 1; i < last; ++i)
            {
                if (!mids[s[i]])
                {
                    ++mids_count;
                    mids[s[i]] = true;
                }
                if (mids_count == CHAR_COUNT)
                    break;
            }
            res += mids_count;
        }

        return res;
    }
};
