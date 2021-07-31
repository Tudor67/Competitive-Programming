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
            for(int j = i + 1, kCandidate = N - 1; j < N; ++j){
                while(j < kCandidate && target - nums[i] - nums[j] < nums[kCandidate]){
                    kCandidate -= 1;
                }
                if(kCandidate + 1 < N){
                    kCandidate += 1;
                }
                for(int k: {kCandidate - 1, kCandidate}){
                    if(j < k && k < N){
                        if(abs(target - nums[i] - nums[j] - nums[k]) < abs(target - closestSum)){
                            closestSum = nums[i] + nums[j] + nums[k];
                        }
                    }
                }
            }
        }
        
        return closestSum;
    }
};