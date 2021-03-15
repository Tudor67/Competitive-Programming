class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = 1;
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    int k = lower_bound(arr.begin(), arr.end(), arr[i] / arr[j]) - arr.begin();
                    if(k < N && arr[k] == arr[i] / arr[j]){
                        dp[i] = (dp[i] + 1LL * dp[j] * dp[k]) % MODULO;
                    }
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer += dp[i];
            answer %= MODULO;
        }
        
        return answer;
    }
};