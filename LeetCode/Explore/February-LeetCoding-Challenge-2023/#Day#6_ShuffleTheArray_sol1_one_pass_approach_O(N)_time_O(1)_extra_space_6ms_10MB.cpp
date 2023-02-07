class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);
        for(int i = 0; i < 2 * n; ++i){
            if(i < n){
                res[2 * i] = nums[i];
            }else{
                res[2 * (i - n) + 1] = nums[i];
            }
        }
        return res;
    }
};