#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @leet start
class Solution {
public:
    string shortestCommonSupersequence(const string &s1, const string &s2) {
        if (s1.empty()) return s2;
        if (s2.empty()) return s1;

        int h = s1.size() + 1;
        int w = s2.size() + 1;
        std::vector<int> dp_data(w * h);
        auto dp = [&](int i, int j) -> int& {
            return dp_data[i * w + j];
        };

        for (int i = 0; i <= s1.size(); ++i) {
            dp(i, 0) = i;
        }
        for (int j = 0; j <= s2.size(); ++j) {
            dp(0, j) = j;
        }

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp(i, j) = dp(i - 1, j - 1) + 1;
                } else {
                    dp(i, j) = std::min(dp(i - 1, j), dp(i, j - 1)) + 1;
                }
            }
        }

        string res = "";
        int i = s1.size(), j = s2.size();

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                res += s1[i - 1];
                --i;
                --j;
            } else if (dp(i - 1, j) < dp(i, j - 1)) {
                res += s1[i - 1];
                i--;
            } else {
                res += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            res += s1[i - 1];
            --i;
        }
        while (j > 0) {
            res += s2[j - 1];
            --j;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @leet end

int main()
{
    std::cout << Solution{}.shortestCommonSupersequence("abac", "cab") << std::endl;
    return 0;
}
