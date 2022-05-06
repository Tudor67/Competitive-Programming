class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i + 1 < N; i += 2){
            if(nums[i] != nums[i + 1]){
                return false;
            }
        }
        
        return true;
    }
};