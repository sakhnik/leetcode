#include <vector>

using namespace std;

// @leet start
class Solution {
public:

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        auto key = [numCourses](int u, int v) {
            return u * numCourses + v;
        };
        std::vector<char> is_prereq;
        is_prereq.resize(numCourses * numCourses, 0);
        for (const auto &p : prerequisites) {
            is_prereq[key(p[0], p[1])] = true;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    auto &p = is_prereq[key(i, j)];
                    p = p || is_prereq[key(i, k)] && is_prereq[key(k, j)];
                }
            }
        }

        vector<bool> res;
        res.reserve(queries.size());
        for (const auto &q : queries) {
            res.push_back(is_prereq[key(q[0], q[1])]);
        }

        return res;
    }
};
// @leet end
