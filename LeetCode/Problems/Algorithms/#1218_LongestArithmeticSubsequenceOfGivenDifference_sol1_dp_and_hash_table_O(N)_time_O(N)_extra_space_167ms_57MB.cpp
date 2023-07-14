class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int N = arr.size();

        int res = 0;

        // At ith step:
        //    maxLen[arr[i]]: max length of a subsequence (from arr[0 .. i]) ending with element arr[i]
        unordered_map<int, int> maxLen;
        for(int elem: arr){
            int prevElem = elem - difference;
            maxLen[elem] = max(maxLen[elem], maxLen[prevElem] + 1);
            res = max(res, maxLen[elem]);
        }

        return res;
    }
};