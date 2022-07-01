class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        while(k > 0){
            for(int i = 0; i < N; ++i){
                if(k > 0 && (i == 0 || v[i - 1] - 1 == v[i])){
                    v[i] += 1;
                    k -= 1;
                }else{
                    break;
                }
            }
        }
        
        long long p = 1;
        for(int i = 0; i < N; ++i){
            p *= v[i];
            p %= MODULO;
        }
        
        return p;
    }
};