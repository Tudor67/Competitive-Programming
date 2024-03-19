class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        const int N = nums.size();

        // Case 1: (numsScore != 0)
        int numsScore = nums[0];
        for(int num: nums){
            numsScore &= num;
        }

        if(numsScore != 0){
            return 1;
        }

        // Case 2: (numsScore == 0)
        int res = 0;
        int score = nums[0];
        for(int i = 0; i < N; ++i){
            score &= nums[i];
            if(score == 0){
                res += 1;
                score = nums[min(N - 1, i + 1)];
            }
        }

        return res;
    }
};