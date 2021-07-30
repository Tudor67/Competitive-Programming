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
                long long targetSum = target - ((long long)nums[i] + nums[j]);
                int k = j + 1;
                int p = N - 1;
                while(k < p){
                    int sum = nums[k] + nums[p];
                    if(sum < targetSum){
                        k += 1;
                    }else if(sum > targetSum){
                        p -= 1;
                    }else{
                        if(answer.empty() || answer.back() != vector<int>{nums[i], nums[j], nums[k], nums[p]}){
                            answer.push_back({nums[i], nums[j], nums[k], nums[p]});
                        }
                        k += 1;
                        p -= 1;
                    }
                }
            }
        }
        
        return answer;
    }
};