class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            res ^= nums[i];
            res ^= (i + 1);
        }

        return res;
    }
};