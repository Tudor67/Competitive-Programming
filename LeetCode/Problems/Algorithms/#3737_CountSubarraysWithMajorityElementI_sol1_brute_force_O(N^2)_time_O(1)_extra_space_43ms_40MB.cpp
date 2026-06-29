class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int N = nums.size();

        int majoritySubarrays = 0;
        
        for(int i = 0; i < N; ++i){
            int targetCount = 0;
            for(int j = i; j < N; ++j){
                if(nums[j] == target){
                    targetCount += 1;
                }
                if(2 * targetCount > j - i + 1){
                    majoritySubarrays += 1;
                }
            }
        }

        return majoritySubarrays;
    }
};