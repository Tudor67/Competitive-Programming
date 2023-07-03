class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        const int N = rods.size();
        const int TOTAL_SUM = accumulate(rods.begin(), rods.end(), 0);

        // dp[diff] = taller
        // dp[diff] contains the taller rod sequence of all (shorter seq, taller seq) pairs
        //          when diff = taller - shorter
        unordered_map<int, int> dp = {{0, 0}};
        unordered_map<int, int> nextDP;

        for(int r: rods){
            nextDP = dp;
            for(const pair<int, int>& P: dp){
                int diff = P.first;
                int taller = dp[diff];
                int shorter = taller - diff;

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