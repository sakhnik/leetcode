#include <string>
#include <stack>

using namespace std;

// @leet start
class Solution {
public:
    string smallestNumber(string pattern) {
        std::string res;
        std::stack<int> s;
        for (int i = 0; i <= pattern.size(); ++i) {
            s.push(i + 1);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!s.empty()) {
                    res.push_back('0' + s.top());
                    s.pop();
                }
            }
        }
        return res;
    }
};
// @leet end
