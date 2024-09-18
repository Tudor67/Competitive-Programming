class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int res = 0;
        int prefSum = 0;
        for(int num: nums){
            prefSum += num;
            if(prefSum == 0){
                res += 1;
            }
        }
        return res;
    }
};