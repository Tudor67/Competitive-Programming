class Solution {
private:
    const int INF = 1e8;
    
    int solve(int j, int k, vector<int>& nums, vector<int>& prefMax, vector<int>& prefSum, vector<vector<int>>& memo){
        if(memo[j][k] != INF){
            return memo[j][k];
        }else if(j == 0){
            memo[j][k] = 0;
        }else if(k == 0){
            memo[j][k] = (j + 1) * prefMax[j] - prefSum[j];
        }else{
            int minCost = INF;
            int suffMax = nums[j];
            int suffSum = nums[j];
            for(int i = j - 1; i >= 0; --i){
                int cost = solve(i, k - 1, nums, prefMax, prefSum, memo) + (j - i) * suffMax - suffSum;
                minCost = min(minCost, cost);
                suffMax = max(suffMax, nums[i]);
                suffSum += nums[i];
            }
            memo[j][k] = minCost;
        }
        return memo[j][k];
    }
    
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> prefMax(N);
        vector<int> prefSum(N);
        prefMax[0] = nums[0];
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], nums[i]);
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        vector<vector<int>> memo(N, vector<int>(k + 1, INF));
        return solve(N - 1, k, nums, prefMax, prefSum, memo);
    }
};