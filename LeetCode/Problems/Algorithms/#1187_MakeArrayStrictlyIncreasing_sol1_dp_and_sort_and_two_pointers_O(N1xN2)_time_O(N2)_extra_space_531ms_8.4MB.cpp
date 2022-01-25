class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {        
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        
        const int N1 = arr1.size();
        const int N2 = arr2.size();
        const int INF = 1e9;
        
        // At step i:
        //    dp[i][j]: min operations to make arr1[0 .. i] strictly increasing
        //              and ending with value <= currentValues[j]
        //              currentValues is sorted array: arr2 + [arr1[i]] of size N2 + 1
        vector<vector<int>> dp(2, vector<int>(N2 + 1));
        vector<int> currentValues = arr2;
        vector<int> previousValues = arr2;
        previousValues.insert(lower_bound(previousValues.begin(), previousValues.end(), arr1[0]), arr1[0]);
        for(int j = 0; j <= N2; ++j){
            if(arr1[0] <= previousValues[j]){
                dp[0][j] = 0;
            }else{
                dp[0][j] = 1;
            }
        }
        
        for(int i = 1; i < N1; ++i){
            fill(dp[i % 2].begin(), dp[i % 2].end(), INF);
            currentValues.insert(lower_bound(currentValues.begin(), currentValues.end(), arr1[i]), arr1[i]);
            
            int k = 0;
            for(int j = 0; j <= N2; ++j){
                int prevVal = previousValues[j];
                while(k <= N2 && currentValues[k] <= prevVal){
                    k += 1;
                }
                if(k <= N2){
                    int currVal = currentValues[k];
                    dp[i % 2][k] = min(dp[i % 2][k], dp[(i - 1) % 2][j] + (int)(currVal != arr1[i]));
                }
            }
            
            for(int j = 1; j <= N2; ++j){
                dp[i % 2][j] = min(dp[i % 2][j], dp[i % 2][j - 1]);
            }
            
            copy(currentValues.begin(), currentValues.end(), previousValues.begin());
            currentValues.erase(lower_bound(currentValues.begin(), currentValues.end(), arr1[i]));
        }
        
        int minOperations = *min_element(dp[(N1 - 1) % 2].begin(), dp[(N1 - 1) % 2].end());
        if(minOperations == INF){
            minOperations = -1;
        }
        
        return minOperations;
    }
};