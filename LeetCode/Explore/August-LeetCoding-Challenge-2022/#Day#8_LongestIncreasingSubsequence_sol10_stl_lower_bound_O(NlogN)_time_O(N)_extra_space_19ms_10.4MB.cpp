class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int num: nums){
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            if(idx >= (int)v.size()){
                v.resize(idx + 1);
            }
            v[idx] = num;
        }
        return v.size();
    }
};