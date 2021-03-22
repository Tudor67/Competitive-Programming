class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        vector<int> maxDec(N, 1);
        vector<int> maxInc(N, 1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    maxInc[i] = max(1 + maxDec[j], maxInc[i]);
                }else if(nums[j] > nums[i]){
                    maxDec[i] = max(1 + maxInc[j], maxDec[i]);
                }
            }
        }
        return max(maxDec[N - 1], maxInc[N - 1]);
    }
};