class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{freq[lhs], -lhs} <
                       pair<int, int>{freq[rhs], -rhs};
             });
        
        return sortedNums;
    }
};