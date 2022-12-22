class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int res = -1;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(int num: nums){
            int len = 1;
            while(num <= MAX_NUM / num && numsSet.count(num * num)){
                num *= num;
                len += 1;
            }
            if(len >= 2){
                res = max(res, len);
            }
        }

        return res;
    }
};