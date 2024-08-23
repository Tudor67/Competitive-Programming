class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCount = 0;
        for(int num: nums){
            evenCount += !(num & 1);
        }
        return (evenCount >= 2);
    }
};