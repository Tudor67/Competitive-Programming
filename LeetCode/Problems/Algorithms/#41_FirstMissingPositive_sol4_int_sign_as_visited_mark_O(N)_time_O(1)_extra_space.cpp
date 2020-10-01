class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i){
            if(nums[i] <= 0){
                nums[i] = N + 1;
            }
        }
        
        for(int i = 0; i < N; ++i){
            int pos = abs(nums[i]) - 1;
            if(pos < N){
                nums[pos] = -abs(nums[pos]);
            }
        }
        
        int answer = N + 1;
        for(int i = 0; i < N; ++i){
            if(nums[i] > 0){
                answer = i + 1;
                break;
            }
        }
        
        return answer;
    }
};