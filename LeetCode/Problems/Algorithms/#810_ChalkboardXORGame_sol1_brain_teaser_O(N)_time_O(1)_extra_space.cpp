class Solution {
public:
    bool xorGame(vector<int>& nums) {
        const int N = nums.size();
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        return (numsXOR == 0 || N % 2 == 0);
    }
};