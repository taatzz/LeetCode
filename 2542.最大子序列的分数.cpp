/*
 * @lc app=leetcode.cn id=2542 lang=cpp
 *
 * [2542] 最大子序列的分数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> f(n);
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return f[n - 1];
    }
};
// @lc code=end

