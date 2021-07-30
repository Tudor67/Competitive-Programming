class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = nums.size();
        
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        vector<vector<int>> answer;
        for(int i = 0; i < N - 3; ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            for(int j = i + 1; j < N - 2; ++j){
                if(j > i + 1 && nums[j - 1] == nums[j]){
                    continue;
                }
                for(int k = j + 1, p = N - 1; k < p; ++k){
                    if(k > j + 1 && nums[k - 1] == nums[k]){
                        continue;
                    }
                    long long targetComplement = target - ((long long)nums[i] + nums[j] + nums[k]);
                    while(k < p && targetComplement < nums[p]){
                        p -= 1;
                    }
                    if(k < p && targetComplement == nums[p]){
                        answer.push_back({nums[i], nums[j], nums[k], (int)targetComplement});
                    }
                }
            }
        }
        
        return answer;
    }
};