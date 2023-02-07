class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);

        int resIndex = 0;
        for(int i = 0; i < n; ++i){
            res[resIndex] = nums[i];
            resIndex += 2;
        }

        resIndex = 1;
        for(int i = n; i < 2 * n; ++i){
            res[resIndex] = nums[i];
            resIndex += 2;
        }

        return res;
    }
};