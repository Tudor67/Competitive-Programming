class Solution {
public:
    int maxSum(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        if(MAX_NUM <= 0){
            return MAX_NUM;
        }

        int res = 0;
        vector<bool> vis(MAX_NUM + 1);
        for(int num: nums){
            if(num >= 1 && !vis[num]){
                vis[num] = true;
                res += num;
            }
        }

        return res;
    }
};