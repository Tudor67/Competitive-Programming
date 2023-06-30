class Solution {
private:
    const int INF = 1e9;

    int getVal(vector<vector<int>>& dp, int i, int j){
        if(i >= 0 && i < (int)dp.size() && j >= 0 && j < (int)dp[i].size()){
            return dp[i][j];
        }
        return INF;
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();

        // At ith iteration:
        //    dp[i % 2][j]: min operations to make arr1[0 .. i] strictly increasing
        //                  and ending with a value <= sortedValues[j]
        //
        //                  sortedValues = sorted(arr2 + [arr1[i]])
        vector<vector<int>> dp(2, vector<int>(N2 + 1));
        vector<int> prevSortedValues;
        vector<int> sortedValues;

        // sort arr2
        vector<int> sortedArr2 = arr2;
        sort(sortedArr2.begin(), sortedArr2.end());
        
        // compute dp[0][..]
        sortedValues = sortedArr2;
        sortedValues.insert(lower_bound(sortedValues.begin(), sortedValues.end(), arr1[0]), arr1[0]);
        for(int j = 0; j <= N2; ++j){
            if(arr1[0] <= sortedValues[j]){
                dp[0][j] = 0;
            }else{
                dp[0][j] = 1;
            }
        }

        // compute dp[1..][..]
        for(int i = 1; i < N1; ++i){
            prevSortedValues = sortedArr2;
            prevSortedValues.insert(lower_bound(prevSortedValues.begin(), prevSortedValues.end(), arr1[i - 1]), arr1[i - 1]);
            sortedValues = sortedArr2;
            sortedValues.insert(lower_bound(sortedValues.begin(), sortedValues.end(), arr1[i]), arr1[i]);

            int k = -1;
            for(int j = 0; j <= N2; ++j){
                while(k + 1 <= N2 && prevSortedValues[k + 1] < sortedValues[j]){
                    k += 1;
                }
                dp[i % 2][j] = min(getVal(dp, i % 2, j - 1),
                                   getVal(dp, (i - 1) % 2, k) + (int)(arr1[i] != sortedValues[j]));
            }
        }

        if(dp[(N1 - 1) % 2][N2] != INF){
            return dp[(N1 - 1) % 2][N2];
        }

        return -1;
    }
};