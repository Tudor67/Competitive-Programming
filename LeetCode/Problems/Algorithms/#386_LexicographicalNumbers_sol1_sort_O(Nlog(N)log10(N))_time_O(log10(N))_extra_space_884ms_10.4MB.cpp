class Solution {
private:
    static bool lexComp(const int& LHS, const int& RHS){
        return (to_string(LHS) < to_string(RHS));
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> sortedNums(n);
        iota(sortedNums.begin(), sortedNums.end(), 1);
        sort(sortedNums.begin(), sortedNums.end(), lexComp);
        return sortedNums;
    }
};