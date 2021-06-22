class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        const int N = nums.size();
        int answer = 0;
        
        int nextValid = -1;
        int nextBigInvalid = N;
        for(int i = N - 1; i >= 0; --i){
            if(nums[i] < left){
                if(nextValid != -1){
                    answer += (nextBigInvalid - nextValid);
                }
            }else if(left <= nums[i] && nums[i] <= right){
                nextValid = i;
                answer += (nextBigInvalid - nextValid);
            }else{
                nextValid = -1;
                nextBigInvalid = i;
            }
        }
        
        return answer;
    }
};