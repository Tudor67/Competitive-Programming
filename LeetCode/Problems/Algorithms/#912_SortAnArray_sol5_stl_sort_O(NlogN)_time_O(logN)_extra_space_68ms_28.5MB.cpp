class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());
        
        return sortedArray;
    }
};