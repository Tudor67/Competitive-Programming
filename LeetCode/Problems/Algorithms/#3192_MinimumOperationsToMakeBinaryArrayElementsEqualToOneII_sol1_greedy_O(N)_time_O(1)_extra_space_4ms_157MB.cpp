class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0;
        for(int num: nums){
            if((num ^ (flips % 2)) == 0){
                flips += 1;
            }
        }
        return flips;
    }
};