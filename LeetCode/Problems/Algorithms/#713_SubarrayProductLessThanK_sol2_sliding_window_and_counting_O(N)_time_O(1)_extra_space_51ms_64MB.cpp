class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        int p = 1;
        int l = 0;
        for(int r = 0; r < N; ++r){
            p *= nums[r];
            while(l <= r && p >= k){
                p /= nums[l];
                l += 1;
            }
            if(p < k){
                res += (r - l + 1);
            }
        }

        return res;
    }
};