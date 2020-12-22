class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int N = nums.size();
        vector<int> answer(N);
        
        int l = 0;
        int r = N - 1;
        for(int i = N - 1; i >= 0; --i){
            if(nums[l] * nums[l] >= nums[r] * nums[r]){
                answer[i] = nums[l] * nums[l];
                l += 1;
            }else{
                answer[i] = nums[r] * nums[r];
                r -= 1;
            }
        }
        
        return answer;
    }
};