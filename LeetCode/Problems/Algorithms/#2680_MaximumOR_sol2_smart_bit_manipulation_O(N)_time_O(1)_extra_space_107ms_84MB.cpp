class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        const int N = nums.size();

        int numsOR = 0;
        int duplicateBitsMask = 0;
        for(int num: nums){
            duplicateBitsMask |= (numsOR & num);
            numsOR |= num;
        }

        long long maxOR = numsOR;
        for(long long num: nums){
            long long currentOR = (numsOR - num) | duplicateBitsMask | (num << k);
            maxOR = max(maxOR, currentOR);
        }

        return maxOR;
    }
};