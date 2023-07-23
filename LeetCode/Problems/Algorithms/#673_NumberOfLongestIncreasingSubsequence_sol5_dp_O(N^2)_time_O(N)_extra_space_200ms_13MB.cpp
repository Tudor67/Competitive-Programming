class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();

        // maxLenAt[i]: length of the longest increasing subsequence of nums[0 .. i] ending with nums[i]
        // countAt[i]: number of longest increasing subsequences of nums[0 .. i] ending with nums[i]
        vector<int> maxLenAt(N, 1);
        vector<int> countAt(N, 1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(maxLenAt[j] + 1 > maxLenAt[i]){
                        maxLenAt[i] = maxLenAt[j] + 1;
                        countAt[i] = countAt[j];
                    }else if(maxLenAt[j] + 1 == maxLenAt[i]){
                        countAt[i] += countAt[j];
                    }
                }
            }
        }
        
        int maxLen = *max_element(maxLenAt.begin(), maxLenAt.end());
        int totalCount = 0;
        for(int i = 0; i < N; ++i){
            if(maxLenAt[i] == maxLen){
                totalCount += countAt[i];
            }
        }

        return totalCount;
    }
};