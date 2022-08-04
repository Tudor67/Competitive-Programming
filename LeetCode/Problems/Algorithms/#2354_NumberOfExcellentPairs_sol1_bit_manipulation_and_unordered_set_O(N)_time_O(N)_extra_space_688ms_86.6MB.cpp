class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        
        // suffCount[c]: count of distinct elements in nums
        //               with number of set bits more than or equal to c
        vector<int> suffCount(61);
        for(int num: numsSet){
            suffCount[__builtin_popcount((unsigned int)num)] += 1;
        }
        
        for(int c = (int)suffCount.size() - 2; c >= 0; --c){
            suffCount[c] += suffCount[c + 1];
        }
        
        long long res = 0;
        for(int num: numsSet){
            res += suffCount[max(0, k - __builtin_popcount((unsigned int)num))];
        }
        
        return res;
    }
};