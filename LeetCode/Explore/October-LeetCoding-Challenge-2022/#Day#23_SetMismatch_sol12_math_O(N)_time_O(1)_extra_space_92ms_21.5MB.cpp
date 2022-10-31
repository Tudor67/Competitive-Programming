class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        long long diff = 0;
        long long diffOfSquares = 0;
        for(int i = 0; i < N; ++i){
            diff += (i + 1) - nums[i];
            diffOfSquares += ((i + 1) * 1LL * (i + 1)) - (nums[i] * 1LL * nums[i]);
        }
        
        long long sum = diffOfSquares / diff;
        
        int duplicate = (sum - diff) / 2;
        int missing = (sum + diff) / 2;
        
        return {duplicate, missing};
    }
};

/*
diff = missing - duplicate = (1 + 2 + ... + N) - (nums[0] + nums[1] + ... + nums[N - 1])
sum = missing + duplicate = (missing^2 - duplicate^2) / (missing - duplicate) = 
                          = [(1^2 + 2^2 + 3^2 + ... + N^2) - (nums[0]^2 + nums[1]^2 + ... + nums[N - 1]^2)] / diff

diff and sum values are computed in a single for loop

duplicate = (sum - diff) / 2;
missing = (sum + diff) / 2;
*/