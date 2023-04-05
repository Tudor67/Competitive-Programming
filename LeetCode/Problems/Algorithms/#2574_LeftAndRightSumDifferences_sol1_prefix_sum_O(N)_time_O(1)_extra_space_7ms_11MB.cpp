class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N);
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        
        for(int i = 0; i < N; ++i){
            rightSum -= nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return answer;
    }
};