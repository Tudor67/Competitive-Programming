class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        for(int i = 1; i * i <= N; ++i){
            if(N % i == 0){
                res += nums[i - 1] * nums[i - 1];
                if(i != N / i){
                    res += nums[N / i - 1] * nums[N / i - 1];
                }
            }
        }

        return res;
    }
};