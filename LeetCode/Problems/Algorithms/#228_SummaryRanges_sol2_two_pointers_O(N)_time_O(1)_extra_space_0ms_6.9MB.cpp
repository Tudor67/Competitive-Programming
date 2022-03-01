class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int N = nums.size();
        
        vector<string> ranges;
        
        int i = 0;
        while(i < N){
            int j = i;
            while(j + 1 < N && nums[j] + 1 == nums[j + 1]){
                j += 1;
            }
            ranges.push_back(to_string(nums[i]));
            if(i != j){
                ranges.back() += "->";
                ranges.back() += to_string(nums[j]);
            }
            i = j + 1;
        }
        
        return ranges;
    }
};