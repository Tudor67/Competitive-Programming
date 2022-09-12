class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int minMoves = 0;
        for(int i = 1; i < N; ++i){
            if(sortedNums[i - 1] >= sortedNums[i]){
                minMoves += (sortedNums[i - 1] - sortedNums[i] + 1);
                sortedNums[i] = sortedNums[i - 1] + 1;
            }
        }
        
        return minMoves;
    }
};