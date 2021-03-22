class Solution {
public:
    int wiggleMaxLength(vector<int>& numsOriginal) {
        // Step 1: remove consecutive duplicates (i.e., [a,a,a,b,b,c,b,b,b] -> [a,b,c,b])
        vector<int> nums = numsOriginal;
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize(it - nums.begin());
        
        // Step 2: answer: the number of local minimum and local maximum points
        //         special case: nums[0] and nums[N - 1]
        const int N = nums.size();
        int answer = 0;
        for(int i = 0; i < N; ++i){
            bool isLocalMin = (i == 0 || nums[i - 1] > nums[i]) && (i == N - 1 || nums[i] < nums[i + 1]);
            bool isLocalMax = (i == 0 || nums[i - 1] < nums[i]) && (i == N - 1 || nums[i] > nums[i + 1]);
            if(isLocalMin || isLocalMax){
                answer += 1;
            }
        }
        
        return answer;
    }
};