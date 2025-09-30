class Solution {
private:
    const int INF = 1e9;

    int f(int l, int r, vector<int>& values, vector<vector<int>>& memo){
        if(memo[l][r] != INF){
            return memo[l][r];
        }
        if(r - l + 1 <= 2){
            memo[l][r] = 0;
        }else{
            for(int k = l + 1; k <= r - 1; ++k){
                memo[l][r] = min(memo[l][r],
                                 values[l] * values[k] * values[r] + f(l, k, values, memo) + f(k, r, values, memo));
            }
        }
        return memo[l][r];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        const int N = values.size();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return f(0, N - 1, values, memo);
    }
};