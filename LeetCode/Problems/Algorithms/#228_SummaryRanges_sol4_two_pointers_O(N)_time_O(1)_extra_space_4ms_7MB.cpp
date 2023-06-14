class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int N = nums.size();

        vector<string> res;

        int l = 0;
        while(l < N){
            int r = l;
            while(r + 1 < N && nums[r] + 1 == nums[r + 1]){
                r += 1;
            }

            if(l == r){
                res.push_back(to_string(nums[l]));
            }else{
                res.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }

            l = r + 1;
        }

        return res;
    }
};