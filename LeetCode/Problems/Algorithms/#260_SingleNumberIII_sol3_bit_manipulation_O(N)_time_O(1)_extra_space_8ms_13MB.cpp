class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const int N = nums.size();

        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }

        int splitMask = 0;
        for(int bit = 0; bit <= 31 && splitMask == 0; ++bit){
            if((numsXOR >> bit) & 1){
                splitMask = (1 << bit);
            }
        }

        int firstNum = 0;
        int secondNum = 0;
        for(int num: nums){
            if(num & splitMask){
                firstNum ^= num;
            }else{
                secondNum ^= num;
            }
        }

        return {firstNum, secondNum};
    }
};