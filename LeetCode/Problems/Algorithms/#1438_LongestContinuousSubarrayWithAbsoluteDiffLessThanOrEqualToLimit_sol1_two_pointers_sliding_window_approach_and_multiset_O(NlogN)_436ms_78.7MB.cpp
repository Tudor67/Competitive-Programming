class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int answer = 0;
        multiset<int> values;
        for(int i = 0, j = 0; j < nums.size(); ++j){
            values.insert(nums[j]);
            while(*values.rbegin() - *values.begin() > limit){
                values.erase(values.find(nums[i]));
                i += 1;
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};