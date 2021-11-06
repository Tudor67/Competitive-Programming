class Solution {
private:
    bool isStrictlyIncreasing(const vector<int>& NUMS, const int& REMOVED_IDX){
        const int N = NUMS.size();
        int prevNum = 0;
        for(int i = 0; i < N; ++i){
            if(i != REMOVED_IDX){
                if(i > 0 && prevNum >= NUMS[i]){
                    return false;
                }
                prevNum = NUMS[i];
            }
        }
        return true;
    }
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i){
            if(isStrictlyIncreasing(nums, i)){
                return true;
            }
        }
        return false;
    }
};