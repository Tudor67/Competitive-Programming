class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end());
        
        for(int p1 = 0; p1 < N - 3; ++p1){
            if(p1 > 0 && nums[p1 - 1] == nums[p1]){
                continue;
            }
            for(int p2 = p1 + 1; p2 < N - 2; ++p2){
                if(p2 > p1 + 1 && nums[p2 - 1] == nums[p2]){
                    continue;
                }
                // p1 and p2 is fixed
                int p3 = p2 + 1;
                int p4 = N - 1;
                while(p3 < p4){
                    int sum = nums[p1] + nums[p2] + nums[p3] + nums[p4];
                    if(sum < target){
                        p3 += 1;
                    }else if(sum > target){
                        p4 -= 1;
                    }else if(sum == target){
                        if(answer.empty() || answer.back() != vector<int>{nums[p1], nums[p2], nums[p3], nums[p4]}){
                            answer.push_back({nums[p1], nums[p2], nums[p3], nums[p4]});
                        }
                        p3 += 1;
                        p4 -= 1;
                    }
                }
            }
        }
        
        return answer;
    }
};