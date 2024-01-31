class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();

        // diff = missing - duplicate = (1 + 2 + 3 + ... + N) - (nums[0] + nums[1] + ... + nums[N - 1])
        // diffOfSquares = missing ^ 2 - duplicate ^ 2 = (1^2 + 2^2 + ... + N^2) - (nums[0]^2 + ... + nums[N - 1]^2)
        long long diff = 0;
        long long diffOfSquares = 0;
        for(int i = 1; i <= N; ++i){
            diff += i;
            diff -= nums[i - 1];
            diffOfSquares += i * i;
            diffOfSquares -= nums[i - 1] * nums[i - 1];
        }

        // sum = missing + duplicate = (missing^2 - duplicate^2) / (missing - duplicate)
        int sum = diffOfSquares / diff;
        int missing = (sum + diff) / 2;
        int duplicate = missing - diff;

        return {duplicate, missing};
    }
};