class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int maxSumSum = INT_MIN;
        int minSumSum = INT_MAX;
        int maxSumDiff = INT_MIN;
        int minSumDiff = INT_MAX;
        int maxDiffSum = INT_MIN;
        int minDiffSum = INT_MAX;
        int maxDiffDiff = INT_MIN;
        int minDiffDiff = INT_MAX;
        
        for(int i = 0; i < arr1.size(); ++i){
            maxSumSum = max(arr1[i] + arr2[i] + i, maxSumSum);
            minSumSum = min(arr1[i] + arr2[i] + i, minSumSum);
            maxSumDiff = max(arr1[i] + arr2[i] - i, maxSumDiff);
            minSumDiff = min(arr1[i] + arr2[i] - i, minSumDiff);
            maxDiffSum = max(arr1[i] - arr2[i] + i, maxDiffSum);
            minDiffSum = min(arr1[i] - arr2[i] + i, minDiffSum);
            maxDiffDiff = max(arr1[i] - arr2[i] - i, maxDiffDiff);
            minDiffDiff = min(arr1[i] - arr2[i] - i, minDiffDiff);
        }
        
        return max({maxSumSum - minSumSum, maxSumDiff - minSumDiff,
                    maxDiffSum - minDiffSum, maxDiffDiff - minDiffDiff});
    }
};