class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int K = 3;
        vector<int> v(K, INT_MAX);
        for(int num: nums){
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
            if(idx == K - 1){
                return true;
            }
        }
        return false;
    }
};