class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        int low = 0; // red in range [0, low - 1]
        int mid = 0; // white in range [low, mid - 1] and unknown in range [mid, high]
        int high = (int)nums.size() - 1; // blue in range [high + 1, nums.size() - 1]
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            }
            else if(nums[mid] == 1){
                ++mid;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};