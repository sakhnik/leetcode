#include <string>

using namespace std;

// @leet start
class Solution {
public:
    string& clearDigits(string &s) {
        size_t o = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (std::isdigit(s[i])) {
                --o;
            } else {
                s[o++] = s[i];
            }
        }
        s.erase(o);
        return s;
    }
};
// @leet end
