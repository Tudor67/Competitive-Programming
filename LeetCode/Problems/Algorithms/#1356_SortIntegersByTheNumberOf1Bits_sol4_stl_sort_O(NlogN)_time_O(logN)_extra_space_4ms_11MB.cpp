class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end(),
             [](int lhs, int rhs){
                 return pair<int, int>{__builtin_popcount(lhs), lhs} <
                        pair<int, int>{__builtin_popcount(rhs), rhs};
             });
        
        return sortedArr;
    }
};