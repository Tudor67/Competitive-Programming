class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        const int N = nums.size();
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int maxNum = 0;
            for(int j = i; maxNum <= right && j < N; ++j){
                maxNum = max(nums[j], maxNum);
                answer += (left <= maxNum && maxNum <= right);
            }
        }
        return answer;
    }
};