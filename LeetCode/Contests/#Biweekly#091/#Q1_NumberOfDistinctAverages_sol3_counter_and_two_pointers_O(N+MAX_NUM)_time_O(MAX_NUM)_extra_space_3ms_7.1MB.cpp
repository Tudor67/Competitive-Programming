class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> numCount(MAX_NUM + 1);
        for(int num: nums){
            numCount[num] += 1;
        }
        
        int l = 0;
        int r = MAX_NUM;
        vector<bool> visAvg(2 * MAX_NUM + 1, false);
        while(l <= r){
            while(l <= r && numCount[l] == 0){
                l += 1;
            }
            while(l <= r && numCount[r] == 0){
                r -= 1;
            }
            if(l <= r){
                visAvg[l + r] = true;
                numCount[l] -= 1;
                numCount[r] -= 1;
            }
        }
        
        return count(visAvg.begin(), visAvg.end(), true);
    }
};