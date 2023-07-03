class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        const int N = rods.size();
        const int TOTAL_SUM = accumulate(rods.begin(), rods.end(), 0);

        // dp[diff] = taller
        // dp[diff] contains the taller rod sequence of all (shorter seq, taller seq) pairs
        //          when diff = taller - shorter
        vector<int> dp(TOTAL_SUM + 1);
        vector<int> nextDP(TOTAL_SUM + 1);

        for(int r: rods){
            nextDP = dp;
            for(int diff = 0; diff <= TOTAL_SUM; ++diff){
                int taller = dp[diff];
                int shorter = taller - diff;

                if(diff >= 1 && taller == 0){
                    continue;
                }

                int nextShorter = shorter;
                int nextTaller = taller + r;
                int nextDiff = nextTaller - nextShorter;
                nextDP[nextDiff] = max(nextDP[nextDiff], nextTaller);

                nextShorter = min(shorter + r, taller);
                nextTaller = max(shorter + r, taller);
                nextDiff = nextTaller - nextShorter;
                nextDP[nextDiff] = max(nextDP[nextDiff], nextTaller);
            }
            dp = nextDP;
        }

        return dp[0];
    }
};