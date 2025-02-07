class Solution {
private:
    int computeMaxLenOfIncSubarray(int i, vector<int>& nums){
        const int N = nums.size();

        int maxLen = 1;
        while(i + 1 < N && nums[i] < nums[i + 1]){
            maxLen += 1;
            i += 1;
        }

        return maxLen;
    }

    int computeMaxLenOfDecSubarray(int i, vector<int>& nums){
        const int N = nums.size();

        int maxLen = 1;
        while(i + 1 < N && nums[i] > nums[i + 1]){
            maxLen += 1;
            i += 1;
        }

        return maxLen;
    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        for(int startIndex = 0; startIndex < N; ++startIndex){
            maxLen = max(maxLen, computeMaxLenOfIncSubarray(startIndex, nums));
            maxLen = max(maxLen, computeMaxLenOfDecSubarray(startIndex, nums));
        }

        return maxLen;
    }
};