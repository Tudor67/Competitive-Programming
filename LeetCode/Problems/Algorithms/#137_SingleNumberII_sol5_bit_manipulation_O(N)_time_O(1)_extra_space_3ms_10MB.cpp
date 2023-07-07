class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;   // contains 1-bits with (frequency % 3 == 1)
        int twos = 0;   // contains 1-bits with (frequency % 3 == 2)
        int threes = 0; // contains 1-bits with (frequency % 3 == 0)
        for(int num: nums){
            twos |= (ones & num);
            ones ^= num;
            threes = (ones & twos);
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};