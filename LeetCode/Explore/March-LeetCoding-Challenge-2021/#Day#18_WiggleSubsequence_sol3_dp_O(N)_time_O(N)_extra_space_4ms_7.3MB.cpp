class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        vector<int> maxDec(N, 1);
        vector<int> maxInc(N, 1);
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] == nums[i]){
                maxDec[i] = maxDec[i - 1];
                maxInc[i] = maxInc[i - 1];
            }else if(nums[i - 1] < nums[i]){
                maxInc[i] = 1 + maxDec[i - 1];
                maxDec[i] = maxDec[i - 1];
            }else if(nums[i - 1] > nums[i]){
                maxInc[i] = maxInc[i - 1];
                maxDec[i] = 1 + maxInc[i - 1];
            }
        }
        return max(maxDec[N - 1], maxInc[N - 1]);
    }
};