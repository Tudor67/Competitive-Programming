class Solution {
private:
    bool containsMonotonicSubarray(vector<int>& nums, int targetLen){
        const int N = nums.size();

        int incAdjPairs = 0;
        int decAdjPairs = 0;
        for(int i = 1; i < N; ++i){
            incAdjPairs += (int)(nums[i - 1] < nums[i]);
            decAdjPairs += (int)(nums[i - 1] > nums[i]);
            if(i >= targetLen){
                incAdjPairs -= (int)(nums[i - targetLen] < nums[i - targetLen + 1]);
                decAdjPairs -= (int)(nums[i - targetLen] > nums[i - targetLen + 1]);
            }
            if(incAdjPairs == targetLen - 1 || decAdjPairs == targetLen - 1){
                return true;
            }
        }

        return false;
    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(containsMonotonicSubarray(nums, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};