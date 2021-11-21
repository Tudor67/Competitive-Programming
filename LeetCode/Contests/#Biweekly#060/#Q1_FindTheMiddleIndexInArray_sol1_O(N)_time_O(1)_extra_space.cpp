class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        const int N = nums.size();
        int lSum = 0;
        int rSum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < N; ++i){
            rSum -= nums[i];
            if(i - 1 >= 0){
                lSum += nums[i - 1];
            }
            if(lSum == rSum){
                return i;
            }
        }
        return -1;
    }
};