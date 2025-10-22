class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int currDistinct = sortedNums[0] - k - 1;
        for(int num: sortedNums){
            int nextDistinct = max(currDistinct + 1, num - k);
            if(nextDistinct <= num + k){
                currDistinct = nextDistinct;
                res += 1;
            }
        }

        return res;
    }
};