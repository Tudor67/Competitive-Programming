class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        
        // dpDec[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are decreasing (nums[j] > nums[i])
        // dpInc[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are increasing (nums[j] < nums[i])
        vector<int> dpDec(N);
        vector<int> dpInc(N);
        for(int i = 0; i < N; ++i){
            dpDec[i] = 1;
            dpInc[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[j] > nums[i]){
                    dpDec[i] = max(dpDec[i], dpInc[j] + 1);
                }else if(nums[j] < nums[i]){
                    dpInc[i] = max(dpInc[i], dpDec[j] + 1);
                }
            }
        }
        
        return max(*max_element(dpDec.begin(), dpDec.end()),
                   *max_element(dpInc.begin(), dpInc.end()));
    }
};