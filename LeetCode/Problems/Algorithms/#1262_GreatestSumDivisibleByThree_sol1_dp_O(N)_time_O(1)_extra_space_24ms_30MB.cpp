class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        unordered_map<int, int> prevMaxSum;
        unordered_map<int, int> currMaxSum;
        prevMaxSum[0] = 0;
        currMaxSum[0] = 0;

        for(int num: nums){
            for(const auto& [prevRem, prevRemMaxSum]: prevMaxSum){
                int currRem = (prevRem + num) % 3;
                currMaxSum[currRem] = max(currMaxSum[currRem], prevRemMaxSum + num);
            }
            prevMaxSum = currMaxSum;
        }

        return currMaxSum[0];
    }
};