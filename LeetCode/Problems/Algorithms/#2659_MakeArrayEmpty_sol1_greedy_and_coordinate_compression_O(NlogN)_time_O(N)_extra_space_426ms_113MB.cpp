class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        map<int, int> maxLen;
        for(int num: nums){
            int compressedNum = lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin();
            if(maxLen.count(compressedNum - 1)){
                maxLen[compressedNum] = maxLen[compressedNum - 1] + 1;
                maxLen.erase(compressedNum - 1);
            }else{
                maxLen[compressedNum] = 1;
            }
        }

        long long totalOperations = 0;
        long long currentSize = N;
        for(const pair<int, int>& P: maxLen){
            int len = P.second;
            totalOperations += currentSize;
            currentSize -= len;
        }

        return totalOperations;
    }
};