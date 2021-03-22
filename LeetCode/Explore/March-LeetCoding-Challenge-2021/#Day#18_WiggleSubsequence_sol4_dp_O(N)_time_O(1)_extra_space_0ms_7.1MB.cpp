class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        int maxDec = 1;
        int maxInc = 1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] < nums[i]){
                maxInc = 1 + maxDec;
            }else if(nums[i - 1] > nums[i]){
                maxDec = 1 + maxInc;
            }
        }
        return max(maxDec, maxInc);
    }
};