class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return *max_element(nums.begin(), nums.end());
        }

        // maxMoney[i]: max money we can rob from nums[0 .. i]
        vector<int> maxMoney(N);
        maxMoney[0] = nums[0];
        maxMoney[1] = max(nums[0], nums[1]);
        for(int i = 2; i < N; ++i){
            maxMoney[i] = max(maxMoney[i - 1], maxMoney[i - 2] + nums[i]);
        }

        return maxMoney[N - 1];
    }
};