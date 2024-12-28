class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        int sum1 = accumulate(nums.begin(), nums.begin() + k, 0);
        int sum1Index = 0;

        int sum2 = accumulate(nums.begin() + k, nums.begin() + 2 * k, 0);
        int sum2Index = k;

        int sum3 = accumulate(nums.begin() + 2 * k, nums.begin() + 3 * k, 0);
        int sum3Index = 2 * k;

        int res1 = sum1;
        vector<int> res1Indices = {sum1Index};

        int res2 = sum1 + sum2;
        vector<int> res2Indices = {sum1Index, sum2Index};

        int res3 = sum1 + sum2 + sum3;
        vector<int> res3Indices = {sum1Index, sum2Index, sum3Index};

        for(int i = 2 * k + 1; i + k - 1 < N; ++i){
            sum1Index += 1;
            sum2Index += 1;
            sum3Index += 1;

            sum1 = sum1 - nums[sum1Index - 1] + nums[sum1Index + k - 1];
            if(res1 < sum1){
                res1 = sum1;
                res1Indices = {sum1Index};
            }

            sum2 = sum2 - nums[sum2Index - 1] + nums[sum2Index + k - 1];
            if(res2 < res1 + sum2){
                res2 = res1 + sum2;
                res2Indices = {res1Indices[0], sum2Index};
            }

            sum3 = sum3 - nums[sum3Index - 1] + nums[sum3Index + k - 1];
            if(res3 < res2 + sum3){
                res3 = res2 + sum3;
                res3Indices = {res2Indices[0], res2Indices[1], sum3Index};
            }
        }

        return res3Indices;
    }
};