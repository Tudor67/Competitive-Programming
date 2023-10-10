class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        const int N = nums.size();

        int identicalPairs = 0;
        unordered_map<int, int> count;
        for(int num: nums){
            identicalPairs += count[num];
            count[num] += 1;
        }

        return identicalPairs;
    }
};