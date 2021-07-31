class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < N; ++i){
            int j = i + 1;
            int k = N - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }
                if(sum < target){
                    j += 1;
                }else if(sum > target){
                    k -= 1;
                }else if(sum == target){
                    return target;
                }
            }
        }
        
        return closestSum;
    }
};