class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefSum = 0;
        int minPrefSum = 0;
        for(int num: nums){
            prefSum += num;
            minPrefSum = min(minPrefSum, prefSum);
        }
        return -minPrefSum + 1;
    }
};