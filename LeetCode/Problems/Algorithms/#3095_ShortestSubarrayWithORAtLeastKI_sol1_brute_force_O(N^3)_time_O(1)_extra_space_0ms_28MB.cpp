class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();

        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int rangeOR = 0;
                for(int j = i; j <= i + len - 1; ++j){
                    rangeOR |= nums[j];
                }
                if(rangeOR >= k){
                    return len;
                }
            }
        }

        return -1;
    }
};