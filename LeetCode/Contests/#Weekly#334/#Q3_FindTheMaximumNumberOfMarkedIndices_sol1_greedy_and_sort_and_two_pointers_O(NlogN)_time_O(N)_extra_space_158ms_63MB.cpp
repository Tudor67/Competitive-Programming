class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int r = N / 2;
        for(int l = 0; l < N / 2; ++l){
            while(r < N && 2 * sortedNums[l] > sortedNums[r]){
                r += 1;
            }
            if(r < N && 2 * sortedNums[l] <= sortedNums[r]){
                r += 1;
                res += 2;
            }
        }

        return res;
    }
};