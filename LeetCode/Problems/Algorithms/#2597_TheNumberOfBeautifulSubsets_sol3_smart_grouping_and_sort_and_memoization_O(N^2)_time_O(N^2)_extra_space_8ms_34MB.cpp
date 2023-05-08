class Solution {
private:
    int solve(int prevIndex, int index, vector<int>& v, int k, vector<vector<int>>& memo){
        if(index >= (int)v.size()){
            return 1;
        }
        if(memo[prevIndex][index] >= 0){
            return memo[prevIndex][index];
        }
        int res = solve(prevIndex, index + 1, v, k, memo);
        if(v[index] - v[prevIndex] != k){
            res += solve(index, index + 1, v, k, memo);
        }
        memo[prevIndex][index] = res;
        return res;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end(),
             [&](int lhs, int rhs){
                 return pair<int, int>{lhs % k, lhs} <
                        pair<int, int>{rhs % k, rhs};
             });
        
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return solve(N - 1, 0, v, k, memo) - 1;
    }
};