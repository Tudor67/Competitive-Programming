class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int minOps = 0;

        vector<int> currNums = nums;

        while(!is_sorted(currNums.begin(), currNums.end())){
            int minSumIdx = 0;
            for(int i = 1; i + 1 < (int)currNums.size(); ++i){
                if(currNums[minSumIdx] + currNums[minSumIdx + 1] > currNums[i] + currNums[i + 1]){
                    minSumIdx = i;
                }
            }

            currNums[minSumIdx] += currNums[minSumIdx + 1];
            currNums.erase(currNums.begin() + minSumIdx + 1);

            minOps += 1;
        }

        return minOps;
    }
};