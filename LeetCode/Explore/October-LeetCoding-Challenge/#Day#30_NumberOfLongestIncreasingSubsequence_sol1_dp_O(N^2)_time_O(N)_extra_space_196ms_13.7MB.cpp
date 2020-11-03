class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        const int N = nums.size();
        vector<int> maxLen(N);
        vector<int> cnt(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    maxLen[i] = max(maxLen[j] + 1, maxLen[i]);
                }
            }
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i] && maxLen[j] + 1 == maxLen[i]){
                    cnt[i] += cnt[j];
                }
            }
            if(maxLen[i] == 0){
                maxLen[i] = 1;
                cnt[i] = 1;
            }
        }
        
        int answer = 0;
        const int MAX_LEN = *max_element(maxLen.begin(), maxLen.end());
        for(int i = 0; i < N; ++i){
            if(maxLen[i] == MAX_LEN){
                answer += cnt[i];
            }
        }
        
        return answer;
    }
};