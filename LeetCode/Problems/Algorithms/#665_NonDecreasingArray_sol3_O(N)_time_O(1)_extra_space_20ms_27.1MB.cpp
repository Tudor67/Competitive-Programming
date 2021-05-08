class Solution {
private:
    bool isNonDecreasingTriplet(vector<int>& nums, int i, int j, int k){
        return (nums[i] <= nums[j] && nums[j] <= nums[k]);
    }
    
public:
    bool checkPossibility(vector<int>& nums) {
        const int N = nums.size();
        bool updated = false;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] > nums[i + 1]){
                if(updated || (0 <= i - 1 && i + 2 < N && !isNonDecreasingTriplet(nums, i - 1, i + 1, i + 2) && !isNonDecreasingTriplet(nums, i - 1, i, i + 2))){
                    return false;
                }
                updated = true;
            }
        }
        return true;
    }
};