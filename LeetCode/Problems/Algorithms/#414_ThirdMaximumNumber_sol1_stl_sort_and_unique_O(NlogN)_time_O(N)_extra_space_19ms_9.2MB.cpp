class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> sortedUniqueNums = nums;
        
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.resize(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()) - sortedUniqueNums.begin());
        
        const int U = sortedUniqueNums.size();
        if(U < 3){
            return sortedUniqueNums.back();
        }
        
        return sortedUniqueNums[U - 3];
    }
};