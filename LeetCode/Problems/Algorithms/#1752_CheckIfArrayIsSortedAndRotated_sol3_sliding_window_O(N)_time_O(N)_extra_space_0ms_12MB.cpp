class Solution {
public:
    bool check(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return true;
        }

        vector<int> nums2(2 * N);
        for(int i = 0; i < N; ++i){
            nums2[i] = nums[i];
            nums2[i + N] = nums[i];
        }

        int wGoodAdjPairs = 0;
        for(int i = 1; i < 2 * N; ++i){
            wGoodAdjPairs += (int)(nums2[i - 1] <= nums2[i]);
            if(i >= N){
                wGoodAdjPairs -= (int)(nums2[i - N] <= nums2[i - N + 1]);
            }
            if(wGoodAdjPairs == N - 1){
                return true;
            }
        }

        return false;
    }
};