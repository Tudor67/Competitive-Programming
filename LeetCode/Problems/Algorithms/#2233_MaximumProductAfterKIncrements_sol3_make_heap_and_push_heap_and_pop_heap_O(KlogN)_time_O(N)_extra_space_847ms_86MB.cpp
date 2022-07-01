class Solution {
private:
    static bool comp(const int& LHS, const int& RHS){
        return (LHS > RHS);
    }
    
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int MODULO = 1e9 + 7;
        
        vector<int> v = nums;
        
        make_heap(v.begin(), v.end(), comp);
        for(int i = 1; i <= k; ++i){
            pop_heap(v.begin(), v.end(), comp);
            v.back() += 1;
            push_heap(v.begin(), v.end(), comp);
        }
        
        long long p = 1;
        for(int elem: v){
            p *= elem;
            p %= MODULO;
        }
        
        return p;
    }
};