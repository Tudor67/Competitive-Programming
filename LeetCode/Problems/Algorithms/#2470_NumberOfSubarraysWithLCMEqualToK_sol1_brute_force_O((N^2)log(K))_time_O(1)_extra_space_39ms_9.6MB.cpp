class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int count = 0;
        for(int i = 0; i < N; ++i){
            int lcmVal = nums[i];
            for(int j = i; j < N && lcmVal <= k; ++j){
                lcmVal = lcm(lcmVal, nums[j]);
                if(lcmVal == k){
                    count += 1;
                }
            }
        }
        
        return count;
    }
};