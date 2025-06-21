class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int minPartitions = 1;
        int l = 0;
        for(int r = 0; r < N; ++r){
            if(sortedNums[r] - sortedNums[l] > k){
                minPartitions += 1;
                l = r;
            }
        }
        
        return minPartitions;
    }
};