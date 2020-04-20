class Solution {
public:
    string getPermutation(int n, int k) {
        string p(n, '0');
        iota(p.begin(), p.end(), '1');
        
        int p_id = 1;
        while(p_id < k){
            next_permutation(p.begin(), p.end());
            ++p_id;
        }
        
        return p;
    }
};