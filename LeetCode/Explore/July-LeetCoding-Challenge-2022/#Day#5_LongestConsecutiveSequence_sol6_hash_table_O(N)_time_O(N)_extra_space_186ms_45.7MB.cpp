class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int N = nums.size();
        
        int maxLen = 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(int num: numsSet){
            if(!numsSet.count(num - 1)){
                int len = 1;
                while(numsSet.count(num + 1)){
                    num += 1;
                    len += 1;
                }
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};