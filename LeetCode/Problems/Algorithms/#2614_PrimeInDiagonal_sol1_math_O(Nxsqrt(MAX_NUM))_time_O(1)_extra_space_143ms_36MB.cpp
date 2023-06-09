class Solution {
private:
    bool isPrime(int x){
        if(x <= 1){
            return false;
        }
        for(int i = 2; i * i <= x; ++i){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
    
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int N = nums.size();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            if(isPrime(nums[i][i])){
                res = max(res, nums[i][i]);
            }
            if(isPrime(nums[i][N - 1 - i])){
                res = max(res, nums[i][N - 1 - i]);
            }
        }

        return res;
    }
};