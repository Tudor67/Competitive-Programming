class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        vector<int> freq(MAX_NUM + 1);
        for(int num: nums){
            freq[num] += 1;
            if(freq[num] >= 3){
                return false;
            }
        }
        return true;
    }
};