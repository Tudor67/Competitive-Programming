class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        map<int, int> suffCount;
        for(int i = N - 1; i >= 0; --i){
            int totalNums = N - 1 - i;
            int goodNums = suffCount[nums[i] - i];
            res += (totalNums - goodNums);
            suffCount[nums[i] - i] += 1;
        }
        
        return res;
    }
};