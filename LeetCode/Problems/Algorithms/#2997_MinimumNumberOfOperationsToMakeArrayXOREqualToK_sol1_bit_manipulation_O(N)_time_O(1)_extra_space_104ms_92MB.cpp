class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();

        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }

        int minOps = 0;
        for(int bit = 0; bit <= 30; ++bit){
            if(((numsXOR ^ k) >> bit) & 1){
                minOps += 1;
            }
        }

        return minOps;
    }
};