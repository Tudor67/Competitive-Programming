class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        const int N = s1.length();

        vector<int> diffs;
        for(int i = 0; i < N; ++i){
            if(s1[i] != s2[i]){
                diffs.push_back(i);
            }
        }

        if(diffs.size() % 2 == 1){
            return -1;
        }

        if(diffs.size() == 0){
            return 0;
        }

        const int D = diffs.size();
        vector<int> dp(D);
        dp[0] = x;
        dp[1] = min(2 * x, 2 * (diffs[1] - diffs[0]));

        for(int i = 2; i < D; ++i){
            dp[i] = min(dp[i - 1] + x, dp[i - 2] + 2 * (diffs[i] - diffs[i - 1]));
        }

        return dp[D - 1] / 2;
    }
};