class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        unordered_set<double> avgSet;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            avgSet.insert((sortedNums[i] + sortedNums[j]) / 2.0);
        }
        
        return avgSet.size();
    }
};