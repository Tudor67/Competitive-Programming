class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int N = nums.size();
        
        vector<int> count(MAX_NUM + 1, 0);
        for(int num: nums){
            count[num] += 1;
        }
        
        int pairsCount = 0;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(num + k <= MAX_NUM){
                pairsCount += count[num] * count[num + k];
            }
        }
        
        return pairsCount;
    }
};