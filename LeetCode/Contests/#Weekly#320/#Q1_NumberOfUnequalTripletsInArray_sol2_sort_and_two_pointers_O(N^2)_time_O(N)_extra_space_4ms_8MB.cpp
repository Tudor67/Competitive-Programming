class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int validTriplets = 0;
        for(int i = 0; i < N; ++i){
            int k = i + 2;
            for(int j = i + 1; j < N; ++j){
                if(sortedNums[i] != sortedNums[j]){
                    while(k < N && sortedNums[j] >= sortedNums[k]){
                        k += 1;
                    }
                    validTriplets += (N - k);
                }
            }
        }

        return validTriplets;
    }
};