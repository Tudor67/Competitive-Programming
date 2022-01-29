class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> onesLeftCount(N);
        onesLeftCount[0] = nums[0];
        for(int i = 1; i < N; ++i){
            if(nums[i] == 1){
                onesLeftCount[i] = onesLeftCount[i - 1] + 1;
            }
        }
        
        vector<int> onesRightCount(N);
        onesRightCount[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] == 1){
                onesRightCount[i] = 1 + onesRightCount[i + 1];
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int l = (i - 1 >= 0 ? onesLeftCount[i - 1] : 0);
            int r = (i + 1 < N ? onesRightCount[i + 1] : 0);
            answer = max(answer, l + r);
        }
        
        return answer;
    }
};