class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return *max_element(nums.begin(), nums.end());
        }

        // At ith iteration:
        //    maxMoney[i % 2]: max money we can rob from nums[0 .. i]
        vector<int> maxMoney(2);
        maxMoney[0] = nums[0];
        maxMoney[1] = max(nums[0], nums[1]);
        for(int i = 2; i < N; ++i){
            maxMoney[i % 2] = max(maxMoney[(i - 1) % 2], maxMoney[(i - 2) % 2] + nums[i]);
        }

        return maxMoney[(N - 1) % 2];
    }
};