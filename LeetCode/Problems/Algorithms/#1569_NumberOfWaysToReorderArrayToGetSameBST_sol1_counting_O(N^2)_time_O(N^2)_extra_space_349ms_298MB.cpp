class Solution {
private:
    const int MODULO = 1e9 + 7;

    long long countBST(vector<int>& nums, vector<vector<long long>>& c){
        if((int)nums.size() <= 2){
            return 1;
        }

        vector<int> leftNums;
        vector<int> rightNums;
        for(int num: nums){
            if(num < nums[0]){
                leftNums.push_back(num);
            }else if(num > nums[0]){
                rightNums.push_back(num);
            }
        }
        
        long long leftCount = countBST(leftNums, c);
        long long rightCount = countBST(rightNums, c);
        long long p = c[leftNums.size() + rightNums.size()][leftNums.size()];

        return (p * ((leftCount * rightCount) % MODULO)) % MODULO;
    }

public:
    int numOfWays(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
        for(int i = 0; i <= N; ++i){
            c[i][0] = 1;
            for(int j = 1; j <= i; ++j){
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
            }
        }

        return (countBST(nums, c) - 1 + MODULO) % MODULO;
    }
};