class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        
        for(int i = 1; i <= k - 1; ++i){
            reverse(a.begin() + i, a.end());
        }
        
        return a;
    }
};