class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int j = 0;
        for(int i = 0; i < N; ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                // avoid duplicates
                continue;
            }
            j = max(j, i + 1);
            while(j < N && nums[j] - nums[i] < k){
                ++j;
            }
            if(j < N && nums[j] - nums[i] == k){
                ++answer;
            }
        }
        
        return answer;
    }
};