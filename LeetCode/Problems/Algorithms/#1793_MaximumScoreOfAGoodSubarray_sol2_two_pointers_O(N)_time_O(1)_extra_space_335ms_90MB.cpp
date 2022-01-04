class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int maxScore = nums[k];
        int minNum = nums[k];
        int i = k - 1;
        int j = k + 1;
        while(i >= 0 || j <= N - 1){
            if(i >= 0 && (j == N || nums[i] >= nums[j])){
                minNum = min(minNum, nums[i]);
                i -= 1;
            }else{
                minNum = min(minNum, nums[j]);
                j += 1;
            }
            int score = minNum * (j - i - 1);
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};