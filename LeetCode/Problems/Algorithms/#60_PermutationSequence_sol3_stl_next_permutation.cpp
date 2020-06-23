class Solution {
public:
    string getPermutation(int n, int k) {
        string p(n, '.');
        iota(p.begin(), p.end(), '1');
        for(; k > 1; --k){
            next_permutation(p.begin(), p.end());
        }
        return p;
    }
};