class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> v = nums;
        
        while((int)v.size() > 1){
            for(int i = 0; i + 1 < (int)v.size(); ++i){
                v[i] += v[i + 1];
                v[i] %= 10;
            }
            v.pop_back();
        }
        
        return v[0];
    }
};