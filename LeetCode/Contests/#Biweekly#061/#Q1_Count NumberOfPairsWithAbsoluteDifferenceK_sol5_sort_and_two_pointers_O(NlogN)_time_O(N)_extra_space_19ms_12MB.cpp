class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        int pairsCount = 0;
        int j1 = 0;
        int j2 = 0;
        for(int i = 0; i < N && j1 < N; ++i){
            j1 = max(j1, i);
            while(j1 < N && sortedNums[j1] < sortedNums[i] + k){
                ++j1;
            }
            j2 = max(j2, i);
            while(j2 < N && sortedNums[j2] <= sortedNums[i] + k){
                ++j2;
            }
            if(j1 < N && sortedNums[j1] == sortedNums[i] + k){
                pairsCount += (j2 - j1);
            }
        }
        
        return pairsCount;
    }
};