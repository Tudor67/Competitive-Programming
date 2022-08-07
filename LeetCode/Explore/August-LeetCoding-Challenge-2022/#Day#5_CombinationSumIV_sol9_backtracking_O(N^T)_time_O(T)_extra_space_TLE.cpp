class Solution {
private:
    void back(vector<int>& nums, int target, int& res){
        if(target == 0){
            res += 1;
        }else{
            for(int num: nums){
                if(target - num >= 0){
                    back(nums, target - num, res);
                }
            }
        }
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        back(nums, target, res);
        return res;
    }
};