class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> prefMin(N);
        prefMin[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMin[i] = min(prefMin[i - 1], nums[i]);
        }
        
        vector<int> suffMax(N);
        suffMax[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(nums[i], suffMax[i + 1]);
        }
        
        for(int i = 1; i + 1 < N; ++i){
            if(prefMin[i - 1] < nums[i] && nums[i] < suffMax[i + 1]){
                return true;
            }
        }
        
        return false;
    }
};