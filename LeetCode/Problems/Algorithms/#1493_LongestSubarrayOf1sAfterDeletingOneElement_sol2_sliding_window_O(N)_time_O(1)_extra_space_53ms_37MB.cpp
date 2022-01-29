class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        int answer = 0;
        int zeros = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            zeros += (int)(nums[j] == 0);
            while(zeros > 1){
                zeros -= (int)(nums[i] == 0);
                i += 1;
            }
            answer = max(answer, j - i);
        }
        
        return answer;
    }
};