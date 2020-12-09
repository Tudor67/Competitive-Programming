class Solution {
private:
    static bool comp(const int& LHS, const int& RHS){
        int leftPopCount = __builtin_popcount(LHS);
        int rightPopCount = __builtin_popcount(RHS);
        return (leftPopCount < rightPopCount || (leftPopCount == rightPopCount && LHS < RHS));
    }
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};