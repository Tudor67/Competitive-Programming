class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> partiallySortedNums = nums;
        partial_sort(partiallySortedNums.begin(), partiallySortedNums.begin() + 2, partiallySortedNums.end(),
                     [](const int& LHS, const int& RHS){
                         return (LHS > RHS);
                     });
        
        return (partiallySortedNums[0] - 1) * (partiallySortedNums[1] - 1);
    }
};