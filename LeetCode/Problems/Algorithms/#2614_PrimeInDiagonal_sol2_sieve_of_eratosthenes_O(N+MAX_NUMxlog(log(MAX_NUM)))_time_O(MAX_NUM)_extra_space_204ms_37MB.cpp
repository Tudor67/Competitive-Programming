class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int N = nums.size();

        int maxNum = nums[0][0];
        for(int i = 0; i < N; ++i){
            maxNum = max(maxNum, nums[i][i]);
            maxNum = max(maxNum, nums[i][N - 1 - i]);
        }

        vector<bool> isPrime(maxNum + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= maxNum; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= maxNum; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(isPrime[nums[i][i]]){
                res = max(res, nums[i][i]);
            }
            if(isPrime[nums[i][N - 1 - i]]){
                res = max(res, nums[i][N - 1 - i]);
            }
        }

        return res;
    }
};