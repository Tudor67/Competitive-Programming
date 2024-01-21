class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(N % (i + 1) == 0){
                res += nums[i] * nums[i];
            }
        }
        
        return res;
    }
};