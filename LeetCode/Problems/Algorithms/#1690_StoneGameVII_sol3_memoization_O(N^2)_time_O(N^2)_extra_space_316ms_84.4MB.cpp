class Solution {
private:
    const int INF = 1e9;
    
    int rangeSum(vector<int>& prefixSum, int start, int end){
        if(start == 0){
            return prefixSum[end];
        }
        return prefixSum[end] - prefixSum[start - 1];
    }
    
    int solve(int i, int j, vector<int>& stones, vector<int>& prefixSum, vector<vector<int>>& memo){
        int sol = 0;
        if(i == j){
            sol = 0;
        }else if(memo[i][j] != -INF){
            sol = memo[i][j];
        }else{
            sol = max(rangeSum(prefixSum, i + 1, j) - solve(i + 1, j, stones, prefixSum, memo),
                      rangeSum(prefixSum, i, j - 1) - solve(i, j - 1, stones, prefixSum, memo));
            memo[i][j] = sol;
        }
        return sol;
    }
    
public:
    int stoneGameVII(vector<int>& stones) {
        const int N = stones.size();
        
        vector<int> prefixSum(N);
        prefixSum[0] = stones[0];
        for(int i = 1; i < N; ++i){
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        
        vector<vector<int>> memo(N, vector<int>(N, -INF));
        int diff = solve(0, N - 1, stones, prefixSum, memo);
        
        return diff;
    }
};