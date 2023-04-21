class Solution {
public:
    int profitableSchemes(int N, int minProfit, vector<int>& group, vector<int>& profit) {
        const int G = group.size();
        const int MODULO = 1e9 + 7;

        // At (groupIdx)th iteration:
        // dp[groupIdx % 2][members][prof]: number of different subsets with profit prof
        //                                  and total number of participants equal to members
        //                                  when we use only groups from group[0 .. groupIdx]
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(N + 2, vector<int>(minProfit + 2)));

        // Step 1: Base cases of DP
        int members0 = min(group[0], N + 1);
        int prof0 = min(profit[0], minProfit + 1);
        dp[0][members0][prof0] = 1;
        dp[0][0][0] = 1;

        // Step 2: DP
        for(int groupIdx = 0; groupIdx + 1 < G; ++groupIdx){
            int nextGroupIdx = groupIdx + 1;
            dp[nextGroupIdx % 2] = dp[groupIdx % 2];

            for(int members = 0; members <= N + 1; ++members){
                for(int prof = 0; prof <= minProfit + 1; ++prof){
                    int nextMembers = min(members + group[nextGroupIdx], N + 1);
                    int nextProf = min(prof + profit[nextGroupIdx], minProfit + 1);
                    dp[nextGroupIdx % 2][nextMembers][nextProf] += dp[groupIdx % 2][members][prof];
                    dp[nextGroupIdx % 2][nextMembers][nextProf] %= MODULO;
                }
            }
        }

        // Step 3: Result
        int res = 0;
        for(int members = 0; members <= N; ++members){
            res += dp[(G - 1) % 2][members][minProfit];
            res %= MODULO;
            res += dp[(G - 1) % 2][members][minProfit + 1];
            res %= MODULO;
        }

        return res;
    }
};