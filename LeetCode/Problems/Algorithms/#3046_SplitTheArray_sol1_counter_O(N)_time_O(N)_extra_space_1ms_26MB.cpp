class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
            if(freq[num] >= 3){
                return false;
            }
        }
        return true;
    }
};