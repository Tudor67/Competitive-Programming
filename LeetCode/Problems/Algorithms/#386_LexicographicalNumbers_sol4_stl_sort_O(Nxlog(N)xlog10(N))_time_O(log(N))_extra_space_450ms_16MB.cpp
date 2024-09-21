class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        iota(res.begin(), res.end(), 1);
        sort(res.begin(), res.end(),
             [](int lhs, int rhs){
                return to_string(lhs) < to_string(rhs);
             });
        return res;
    }
};