
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);

        //Store prerequisites as bitmasks
        for (auto& r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;

            prereq[v] |= (1 << u);
        }

        int total = 1 << n;

        // dp[mask] = minimum semesters needed to complete mask
        vector<int> dp(total, n + 1);
        dp[0] = 0;

        //Explore every possible completed-course state
        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] == n + 1) {
                continue;
            }

            int available = 0;

            //Find courses whose prerequisites are satisfied
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 &&
                    (mask & prereq[i]) == prereq[i]) {
                    available |= (1 << i);
                }
            }

            //Try every non-empty subset of available courses
            for (int sub = available; sub > 0;
                 sub = (sub - 1) & available) {

                // At most k courses per semester
                if (__builtin_popcount((unsigned)sub) > k) {
                    continue;
                }

                int nextMask = mask | sub;

                dp[nextMask] = min(
                    dp[nextMask],
                    dp[mask] + 1
                );
            }
        }

        // All courses completed
        return dp[total - 1];
    }
};
