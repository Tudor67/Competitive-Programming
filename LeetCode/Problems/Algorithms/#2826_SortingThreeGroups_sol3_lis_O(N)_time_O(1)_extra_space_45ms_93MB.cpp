class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();

        // At ith iteration:
        //    maxLen[x]: length of the longest non-decreasing subsequence
        //               with the max element equal to x
        vector<int> maxLen(4);
        for(int num: nums){
            maxLen[num] = 1 + *max_element(maxLen.begin(), maxLen.begin() + num + 1);
        }

        return N - *max_element(maxLen.begin(), maxLen.end());
    }
};