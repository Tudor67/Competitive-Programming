class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> freq(MAX_NUM + 1);
        for(int num: nums){
            freq[num] += 1;
        }

        for(int numFreq: freq){
            if(numFreq % 2 == 1){
                return false;
            }
        }

        return true;
    }
};