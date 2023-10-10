class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int identicalPairs = 0;
        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            identicalPairs += count[num];
            count[num] += 1;
        }

        return identicalPairs;
    }
};