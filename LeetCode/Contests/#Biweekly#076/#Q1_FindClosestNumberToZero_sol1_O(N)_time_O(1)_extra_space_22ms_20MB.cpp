class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for(int num: nums){
            if(abs(num) < abs(res) || (abs(num) == abs(res) && num > res)){
                res = num;
            }
        }
        return res;
    }
};