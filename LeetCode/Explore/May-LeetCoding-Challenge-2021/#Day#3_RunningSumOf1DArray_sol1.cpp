class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefSum = nums;
        for(int i = 1; i < (int)prefSum.size(); ++i){
            prefSum[i] += prefSum[i - 1];
        }
        return prefSum;
    }
};