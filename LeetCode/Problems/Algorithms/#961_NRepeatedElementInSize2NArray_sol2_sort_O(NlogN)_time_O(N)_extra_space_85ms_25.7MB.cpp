class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int N = nums.size() / 2;
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        for(int i = 1; i < 2 * N; ++i){
            if(sortedNums[i - 1] == sortedNums[i]){
                return sortedNums[i];
            }
        }
        
        return -1;
    }
};