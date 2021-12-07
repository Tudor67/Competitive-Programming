class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        int pairsCount = 0;
        for(int i = 0; i < N; ++i){
            auto it1 = lower_bound(sortedNums.begin() + i, sortedNums.end(), sortedNums[i] + k);
            auto it2 = upper_bound(sortedNums.begin() + i, sortedNums.end(), sortedNums[i] + k);
            if(it1 != sortedNums.end() && *it1 == sortedNums[i] + k){
                pairsCount += (it2 - it1);
            }
        }
        
        return pairsCount;
    }
};