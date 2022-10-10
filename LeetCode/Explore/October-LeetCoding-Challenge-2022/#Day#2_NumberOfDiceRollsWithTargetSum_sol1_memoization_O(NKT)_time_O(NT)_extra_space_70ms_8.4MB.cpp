class Solution {
private:
    const int MODULO = 1e9 + 7;
    const int INF = 2e9;
    
    int solve(int n, int k, int target, vector<vector<int>>& memo){
        if(target < 0){
            return 0;
        }else if(n == 0){
            return (target == 0);
        }else if(memo[n][target] == -INF){
            int count = 0;
            for(int i = 1; i <= k; ++i){
                count += solve(n - 1, k, target - i, memo);
                count %= MODULO;
            }
            memo[n][target] = count;
        }
        return memo[n][target];
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -INF));
        return solve(n, k, target, memo);
    }
};