class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
            if(count[num] == 2){
                return num;
            }
        }
        return -1;
    }
};