class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int totalXORSum = 0;
        for(int bit = 0; (1 << bit) <= MAX_NUM; ++bit){
            int oneBitsCount = 0;
            for(int num: nums){
                oneBitsCount += (num >> bit) & 1;
            }
            if(oneBitsCount >= 1){
                totalXORSum += (1 << bit) * (1 << (N - 1));
            }
        }

        return totalXORSum;
    }
};