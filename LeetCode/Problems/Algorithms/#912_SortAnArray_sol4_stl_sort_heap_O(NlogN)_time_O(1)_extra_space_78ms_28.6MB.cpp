class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedArray = nums;
        
        make_heap(sortedArray.begin(), sortedArray.end());
        sort_heap(sortedArray.begin(), sortedArray.end());
        
        return sortedArray;
    }
};