class Solution {
private:
    vector<vector<int>> memo;
    
    int solve(int k, int n){
        if(memo[k][n] == -1){
            if(k == 1 || n == 0){
                memo[k][n] = n;
            }else{
                int minWorstCost = n;
                int l = 1;
                int r = n;
                while(true){
                    int mid = (l + r) / 2;
                    int f = mid;
                    int breakCost = 1 + solve(k - 1, f - 1);
                    int resistCost = 1 + solve(k, n - f);
                    int worstCost = max(breakCost, resistCost);
                    minWorstCost = min(worstCost, minWorstCost);
                    if(l == r){
                        break;
                    }
                    if(breakCost < resistCost){
                        l = mid + 1;
                    }else{
                        r = mid;
                    }
                }
                memo[k][n] = minWorstCost;
            }
        }
        return memo[k][n];
    }
    
public:
    int superEggDrop(int k, int n) {
        memo.resize(k + 1, vector<int>(n + 1));
        for(int i = 0; i <= k; ++i){
            fill(memo[i].begin(), memo[i].end(), -1);
        }
        return solve(k, n);
    }
};