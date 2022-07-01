class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedArray = nums;
        make_heap(sortedArray.begin(), sortedArray.end());
        for(int i = N; i >= 1; --i){
            pop_heap(sortedArray.begin(), sortedArray.begin() + i);
        }
        
        return sortedArray;
    }
};