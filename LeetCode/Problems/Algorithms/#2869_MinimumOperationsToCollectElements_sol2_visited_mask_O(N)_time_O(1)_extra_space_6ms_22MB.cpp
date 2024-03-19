class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long FULL_MASK = (1LL << k) - 1;

        long long visMask = 0;
        for(int i = N - 1; i >= 0; --i){
            if(nums[i] <= k){
                visMask |= (1LL << (nums[i] - 1));
            }
            if(visMask == FULL_MASK){
                return N - i;
            }
        }

        return -1;
    }
};