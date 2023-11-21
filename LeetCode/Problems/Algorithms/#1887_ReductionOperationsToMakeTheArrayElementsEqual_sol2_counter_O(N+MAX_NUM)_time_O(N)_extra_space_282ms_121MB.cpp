class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        int res = 0;
        int distinctNums = 0;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(freq.count(num)){
                distinctNums += 1;
                res += (distinctNums - 1) * freq[num];
            }
        }

        return res;
    }
};