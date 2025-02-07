class Solution {
public:
    bool check(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return true;
        }

        int wGoodAdjPairs = 0;
        for(int i = 1; i < 2 * N; ++i){
            wGoodAdjPairs += (int)(nums[(i - 1) % N] <= nums[i % N]);
            if(i >= N){
                wGoodAdjPairs -= (int)(nums[(i - N) % N] <= nums[(i - N + 1) % N]);
            }
            if(wGoodAdjPairs == N - 1){
                return true;
            }
        }

        return false;
    }
};