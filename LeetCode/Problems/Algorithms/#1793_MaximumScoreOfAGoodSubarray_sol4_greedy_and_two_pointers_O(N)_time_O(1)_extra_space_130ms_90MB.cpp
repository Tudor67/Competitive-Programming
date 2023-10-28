class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = nums[k];
        int minNum = nums[k];
        int i = k - 1;
        int j = k + 1;
        while(i >= 0 || j <= N - 1){
            if(j == N || (i >= 0 && nums[i] >= nums[j])){
                minNum = min(minNum, nums[i]);
                i -= 1;
            }else{
                minNum = min(minNum, nums[j]);
                j += 1;
            }
            int score = minNum * (j - i - 1);
            res = max(res, score);
        }

        return res;
    }
};