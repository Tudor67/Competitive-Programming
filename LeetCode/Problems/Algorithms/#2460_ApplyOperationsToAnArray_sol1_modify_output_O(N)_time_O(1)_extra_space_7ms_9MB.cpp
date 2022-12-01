class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> res;
        int i = 0;
        while(i < N){
            if(i + 1 < N && nums[i] == nums[i + 1]){
                if(nums[i] != 0){
                    res.push_back(2 * nums[i]);
                }
                i += 2;
            }else{
                if(nums[i] != 0){
                    res.push_back(nums[i]);
                }
                i += 1;
            }
        }
        
        res.resize(N);
        
        return res;
    }
};