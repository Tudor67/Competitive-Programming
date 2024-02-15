class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] + nums[j] < target){
                    res += 1;
                }
            }
        }

        return res;
    }
};