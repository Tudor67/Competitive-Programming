class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        const int N = nums.size();
        
        vector<int> v(N - 1, 0);
        for(int i = 0; i < (int)v.size(); ++i){
            if(nums[i] < nums[i + 1]){
                v[i] = 1;
            }else if(nums[i] > nums[i + 1]){
                v[i] = -1;
            }
        }
        
        int matches = 0;
        for(int i = 0; i + (int)pattern.size() - 1 < (int)v.size(); ++i){
            if(equal(pattern.begin(), pattern.end(), v.begin() + i)){
                matches += 1;
            }
        }
        
        return matches;
    }
};