class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);

        vector<int> res(N);
        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            int leftContrib = nums[i] * (i + 1) - prefSum;
            int rightContrib = TOTAL_SUM - prefSum - nums[i] * (N - 1 - i);
            res[i] = leftContrib + rightContrib;
        }

        return res;
    }
};