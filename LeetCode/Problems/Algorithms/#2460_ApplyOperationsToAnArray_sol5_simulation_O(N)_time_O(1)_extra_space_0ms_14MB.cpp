class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        res.reserve(N);
        
        int i = 0;
        while(i < N){
            if(nums[i] >= 1){
                if(i + 1 < N && nums[i] == nums[i + 1]){
                    res.push_back(nums[i] * 2);
                    i += 2;
                }else{
                    res.push_back(nums[i]);
                    i += 1;
                }
            }else{
                i += 1;
            }
        }

        res.resize(N);

        return res;
    }
};