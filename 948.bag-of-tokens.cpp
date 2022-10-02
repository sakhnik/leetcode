#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        int score{}, max_score{};
        for (int l = 0, r = tokens.size() - 1; l <= r; )
        {
            if (power >= tokens[l])
            {
                max_score = std::max(max_score, ++score);
                power -= tokens[l++];
            }
            else if (score > 0)
            {
                --score;
                power += tokens[r--];
            }
            else
                break;
        }
        return max_score;
    }
};
