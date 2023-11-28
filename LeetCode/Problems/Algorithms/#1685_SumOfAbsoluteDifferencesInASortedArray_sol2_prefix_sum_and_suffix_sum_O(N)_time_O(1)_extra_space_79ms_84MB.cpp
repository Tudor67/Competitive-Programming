class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);

        vector<int> res(N);

        int prefSum = 0;
        int suffSum = TOTAL_SUM;
        for(int i = 0; i < N; ++i){
            int prefContrib = i * nums[i] - prefSum;
            int suffContrib = suffSum - (N - i) * nums[i];
            res[i] = prefContrib + suffContrib;
            prefSum += nums[i];
            suffSum -= nums[i];
        }
        
        return res;
    }
};