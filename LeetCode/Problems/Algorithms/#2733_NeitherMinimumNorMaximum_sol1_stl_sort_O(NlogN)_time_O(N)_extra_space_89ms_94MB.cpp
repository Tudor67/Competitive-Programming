class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return -1;
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        return sortedNums[1];
    }
};