class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int N = nums.size();
        
        int maxLen = 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(int num: nums){
            if(numsSet.count(num)){
                numsSet.erase(num);
                
                int r = num + 1;
                while(numsSet.count(r)){
                    numsSet.erase(r);
                    r += 1;
                }
                
                int l = num - 1;
                while(numsSet.count(l)){
                    numsSet.erase(l);
                    l -= 1;
                }
                
                int len = r - l - 1;
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};