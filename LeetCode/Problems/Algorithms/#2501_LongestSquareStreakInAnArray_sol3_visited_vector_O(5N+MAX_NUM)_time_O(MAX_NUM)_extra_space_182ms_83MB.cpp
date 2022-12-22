class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);
        for(int num: nums){
            vis[num] = true;
        }

        int res = -1;
        for(int num: nums){
            int len = 1;
            while(num <= MAX_NUM / num && vis[num * num]){
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