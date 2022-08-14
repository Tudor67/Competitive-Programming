class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int N = arr.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // dp[target]: in how many ways we can write the number target
        //             as a product of one or two elements from sortedArr
        unordered_map<int, int> dp;
        for(int i = 0; i < N; ++i){
            int target = sortedArr[i];
            dp[target] = 1;
            for(int j = 0; j < i; ++j){
                int x = sortedArr[j];
                int y = target / x;
                if(x * y == target && dp.count(y)){
                    dp[target] = (dp[target] + dp[x] * 1LL * dp[y]) % MODULO;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            res = (res + dp[sortedArr[i]]) % MODULO;
        }
        
        return res;
    }
};