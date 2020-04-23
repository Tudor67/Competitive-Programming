class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0; // idx of zero elem
        int j = 0; // idx of non-zero elem
        while(i < n && j < n){
            while(i < n && nums[i] != 0){
                ++i;
            }
            
            j = max(i + 1, j);
            while(j < n && nums[j] == 0){
                ++j;
            }
            
            if(i < n && j < n){
                swap(nums[i], nums[j]);
            }
            
            ++i;
            ++j;
        }
    }
};