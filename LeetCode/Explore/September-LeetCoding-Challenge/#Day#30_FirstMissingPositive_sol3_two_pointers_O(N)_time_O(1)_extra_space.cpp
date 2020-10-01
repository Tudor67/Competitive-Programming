class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();
        
        int l = 0;
        int r = N - 1;
        while(l <= r){
            if(nums[l] <= 0 || nums[l] >= N + 1){
                swap(nums[l], nums[r]);
                r -= 1;
            }else if(nums[l] == nums[nums[l] - 1]){
                l += 1;
            }else{
                swap(nums[l], nums[nums[l] - 1]);
            }
        }
        
        int answer = N + 1;
        for(int i = 0; i < N; ++i){
            if(i + 1 != nums[i]){
                answer = i + 1;
                break;
            }
        }
        
        return answer;
    }
};