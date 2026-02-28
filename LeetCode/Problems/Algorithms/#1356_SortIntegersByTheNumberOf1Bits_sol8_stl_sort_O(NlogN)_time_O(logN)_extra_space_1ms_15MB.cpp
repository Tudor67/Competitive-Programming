class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end(),
             [](int lhs, int rhs){
                return pair<int, int>{popcount((unsigned int)lhs), lhs} <
                       pair<int, int>{popcount((unsigned int)rhs), rhs};
             });
        return sortedArr;
    }
};