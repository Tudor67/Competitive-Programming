class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        while(n > 1){
            for(int i = 0; i + 1 < n; ++i){
                v[i] += v[i + 1];
                v[i] %= 10;
            }
            n -= 1;
        }
        return v[0];
    }
};