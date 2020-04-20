class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v(1 << n);
        
        for(int p = 1; (1 << p) <= v.size(); ++p){
            int mid = (1 << p) / 2;
            
            // reflect
            copy(v.begin(), v.begin() + mid, v.begin() + mid);
            reverse(v.begin() + mid, v.begin() + 2 * mid);
            
            // prefix
            for(int i = mid; i < 2 * mid; ++i){
                v[i] += mid;
            }
        }
        
        return v;
    }
};