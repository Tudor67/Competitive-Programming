class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int N = arr.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // dp[i]: in how many ways we can write the number sortedArr[i]
        //        as a product of one or two elements from sortedArr[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = 1;
            int j = 0;
            int k = i - 1;
            while(j < i && k >= 0){
                long long prod = sortedArr[j] * 1LL * sortedArr[k];
                if(prod == sortedArr[i]){
                    dp[i] = (dp[i] + dp[j] * 1LL * dp[k]) % MODULO;
                    j += 1;
                    k -= 1;
                }else if(prod < sortedArr[i]){
                    j += 1;
                }else{
                    k -= 1;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            res = (res + dp[i]) % MODULO;
        }
        
        return res;
    }
};