class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MODULO = 1'000'000'007;

        vector<int> cntFor(n + 1, -1);
        for(vector<int>& req: requirements){
            cntFor[req[0] + 1] = req[1];
        }
        
        int maxCnt = *max_element(cntFor.begin(), cntFor.end());

        // dp[sz][cnt]: number of valid permutations of size sz and cnt inversions
        vector<vector<int>> dp(n + 1, vector<int>(maxCnt + 1));
        vector<int> delta(maxCnt + 2);
        dp[1][0] = 1;
        
        for(int currSize = 1; currSize + 1 <= n; ++currSize){
            fill(delta.begin(), delta.end(), 0);
            int startCnt = (cntFor[currSize] >= 0 ? cntFor[currSize] : 0);
            int endCnt = (cntFor[currSize] >= 0 ? cntFor[currSize] : maxCnt);
            for(int currCnt = startCnt; currCnt <= endCnt; ++currCnt){
                add(delta[currCnt], dp[currSize][currCnt], MODULO);
                add(delta[min(currCnt + currSize + 1, maxCnt + 1)], MODULO - dp[currSize][currCnt], MODULO);
            }

            int sum = 0;
            for(int cnt = 0; cnt <= maxCnt; ++cnt){
                add(sum, delta[cnt], MODULO);
                dp[currSize + 1][cnt] = sum;
            }
        }

        return dp[n][cntFor[n]];
    }
};