class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> prefMax(N);
        prefMax[0] = nums[0];
        for(int i = 1; i <= N - 1; ++i){
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }
        
        vector<int> suffMin(N);
        suffMin[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        
        for(int i = 0; i <= N - 2; ++i){
            if(prefMax[i] <= suffMin[i + 1]){
                return i + 1;
            }
        }
        
        return -1;
    }
};