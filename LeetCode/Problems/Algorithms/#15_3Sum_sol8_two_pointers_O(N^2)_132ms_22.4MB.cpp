class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> triplets;
        
        sort(nums.begin(), nums.end());
        
        for(int p1 = 0; p1 < N; ++p1){
            if(p1 > 0 && nums[p1 - 1] == nums[p1]){
                continue;
            }
            // p1 is fixed
            int p2 = p1 + 1;
            int p3 = N - 1;
            while(p2 < p3){
                if(nums[p2] + nums[p3] < -nums[p1]){
                    p2 += 1;
                }else if(nums[p2] + nums[p3] > -nums[p1]){
                    p3 -= 1;
                }else if(nums[p2] + nums[p3] == -nums[p1]){
                    if(triplets.empty() || triplets.back() != vector<int>{nums[p1], nums[p2], nums[p3]}){
                        triplets.push_back({nums[p1], nums[p2], nums[p3]});
                    }
                    p2 += 1;
                    p3 -= 1;
                }
            }
        }
        
        return triplets;
    }
};