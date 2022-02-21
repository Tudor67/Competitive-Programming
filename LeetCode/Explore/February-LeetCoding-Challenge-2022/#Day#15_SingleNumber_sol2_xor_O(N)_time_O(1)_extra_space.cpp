class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        return numsXOR;
    }
};