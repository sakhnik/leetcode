#include <string>

using namespace std;

// @leet start
class Solution {
public:
    string& removeOccurrences(string &s, const string &part) {
        ssize_t i = 0;
        size_t j;
        while ((j = s.find(part, i)) != s.npos) {
            s.erase(j, part.size());
            i = j - part.size();
            if (i < 0)
                i = 0;
        }
        return s;
    }
};
// @leet end
