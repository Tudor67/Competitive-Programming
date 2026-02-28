class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        unordered_set<int> vis;

        for(int i = 0; i < N; ++i){
            vis.clear();
            int distinctEvens = 0;
            int distinctOdds = 0;
            for(int j = i; j < N; ++j){
                if(!vis.count(nums[j])){
                    vis.insert(nums[j]);
                    if(nums[j] % 2 == 0){
                        distinctEvens += 1;
                    }else{
                        distinctOdds += 1;
                    }
                }
                if(distinctEvens == distinctOdds){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};