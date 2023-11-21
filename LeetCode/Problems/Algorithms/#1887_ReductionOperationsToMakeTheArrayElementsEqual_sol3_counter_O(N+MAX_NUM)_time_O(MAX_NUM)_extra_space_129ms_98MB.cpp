class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> freq(MAX_NUM + 1);
        for(int num: nums){
            freq[num] += 1;
        }

        int res = 0;
        int distinctNums = 0;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(freq[num] >= 1){
                distinctNums += 1;
                res += (distinctNums - 1) * freq[num];
            }
        }

        return res;
    }
};