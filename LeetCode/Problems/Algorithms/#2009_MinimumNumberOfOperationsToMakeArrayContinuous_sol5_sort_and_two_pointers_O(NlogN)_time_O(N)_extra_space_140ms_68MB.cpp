class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        int minOps = N - 1;
        int j = 0;
        for(int i = 0; i < (int)sortedNums.size(); ++i){
            while(j < (int)sortedNums.size() && sortedNums[j] <= sortedNums[i] + N - 1){
                ++j;
            }
            int ops = N - (j - i);
            minOps = min(minOps, ops);
        }

        return minOps;
    }
};