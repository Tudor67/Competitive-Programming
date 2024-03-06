class Solution {
private:
    int getProductOfPrimesWithOddPow(int x){
        int res = 1;
        
        for(int i = 2; i * i <= x; ++i){
            if(x % i == 0){
                int powParity = 0;
                while(x % i == 0){
                    x /= i;
                    powParity ^= 1;
                }
                if(powParity == 1){
                    res *= i;
                }
            }
        }
        
        if(x > 1){
            res *= x;
        }
        
        return res;
    }
    
public:
    long long maximumSum(vector<int>& nums) {
        const int N = nums.size();
        
        vector<long long> maxSum(N + 1);
        for(int i = 1; i <= N; ++i){
            maxSum[getProductOfPrimesWithOddPow(i)] += nums[i - 1];
        }
        
        return *max_element(maxSum.begin(), maxSum.end());
    }
};