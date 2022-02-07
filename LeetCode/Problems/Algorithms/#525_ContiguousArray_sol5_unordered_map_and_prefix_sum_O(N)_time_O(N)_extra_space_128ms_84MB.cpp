class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> firstPosOf;
        firstPosOf[0] = -1;
        
        int maxLen = 0;
        int bal = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] == 0){
                bal -= 1;
            }else{
                bal += 1;
            }
            if(firstPosOf.count(bal)){
                int len = i - firstPosOf[bal];
                maxLen = max(maxLen, len);
            }else{
                firstPosOf[bal] = i;
            }
        }
        
        return maxLen;
    }
};