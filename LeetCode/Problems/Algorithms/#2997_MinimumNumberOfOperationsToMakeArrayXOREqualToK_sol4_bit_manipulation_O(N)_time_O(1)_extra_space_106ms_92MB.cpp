class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();

        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }

        int minOps = 0;
        int badBitsMask = numsXOR ^ k;
        for(int bit = 0; (badBitsMask >> bit) > 0; ++bit){
            if((badBitsMask >> bit) & 1){
                minOps += 1;
            }
        }

        return minOps;
    }
};