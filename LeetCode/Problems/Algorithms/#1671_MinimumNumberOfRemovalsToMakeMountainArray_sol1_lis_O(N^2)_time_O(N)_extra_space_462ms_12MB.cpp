class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int N = nums.size();
        
        // leftMaxLen[i]: length of the LIS (from left to right) ending with nums[i]
        vector<int> leftMaxLen(N, 1);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    leftMaxLen[i] = max(leftMaxLen[i], leftMaxLen[j] + 1);
                }
            }
        }
        
        // rightMaxLen[i]: length of the LIS (from right to left) ending with nums[i]
        vector<int> rightMaxLen(N, 1);
        for(int i = N - 1; i >= 0; --i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    rightMaxLen[i] = max(rightMaxLen[i], rightMaxLen[j] + 1);
                }
            }
        }
        
        int maxMountainLen = 0;
        for(int i = 0; i < N; ++i){
            if(leftMaxLen[i] >= 2 && rightMaxLen[i] >= 2){
                maxMountainLen = max(maxMountainLen, leftMaxLen[i] + rightMaxLen[i] - 1);
            }
        }
        
        return N - maxMountainLen;
    }
};