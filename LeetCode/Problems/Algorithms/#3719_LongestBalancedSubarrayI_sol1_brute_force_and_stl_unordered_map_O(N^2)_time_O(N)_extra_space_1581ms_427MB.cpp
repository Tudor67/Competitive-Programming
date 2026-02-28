class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        vector<unordered_map<int, int>> freq(2);

        for(int i = 0; i < N; ++i){
            freq[0].clear();
            freq[1].clear();
            for(int j = i; j < N; ++j){
                freq[nums[j] % 2][nums[j]] += 1;
                if(freq[0].size() == freq[1].size()){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};