class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        const int N = nums.size();
        int answer = 0;
        
        int prevL = -1;
        int prevR = -1;
        for(int i = 0; i < N; ++i){
            if(nums[i] >= left){
                prevL = i;
            }
            if(nums[i] > right){
                prevR = i;
            }
            answer += (prevL - prevR);
        }
        
        return answer;
    }
};