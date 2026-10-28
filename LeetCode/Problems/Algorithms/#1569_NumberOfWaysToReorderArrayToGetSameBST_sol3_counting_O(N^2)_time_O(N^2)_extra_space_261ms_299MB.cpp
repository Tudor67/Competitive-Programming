class Solution {
private:
    const long long MODULO = 1'000'000'007;

    long long countWays(vector<int>& nums, vector<vector<long long>>& comb){
        const int N = nums.size();

        if(N <= 1){
            return 1;
        }

        int root = nums[0];
        vector<int> leftNums;
        vector<int> rightNums;

        for(int num: nums){
            if(num < root){
                leftNums.push_back(num);
            }else if(num > root){
                rightNums.push_back(num);
            }
        }

        long long leftCount = countWays(leftNums, comb);
        long long leftLen = leftNums.size();
        long long rightCount = countWays(rightNums, comb);
        long long rightLen = rightNums.size();

        return leftCount * rightCount % MODULO *
               comb[leftLen + rightLen][leftLen] % MODULO;
    }

public:
    int numOfWays(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<long long>> comb(N + 1, vector<long long>(N + 1));
        for(int i = 0; i <= N; ++i){
            comb[i][0] = 1;
            for(int j = 1; j <= i; ++j){
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MODULO;
            }
        }
        
        return (countWays(nums, comb) - 1 + MODULO) % MODULO;
    }
};