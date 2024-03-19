class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0;

        int score = INT_MAX;
        for(int num: nums){
            score &= num;
            if(score == 0){
                res += 1;
                score = INT_MAX;
            }
        }

        res = max(res, 1);

        return res;
    }
};