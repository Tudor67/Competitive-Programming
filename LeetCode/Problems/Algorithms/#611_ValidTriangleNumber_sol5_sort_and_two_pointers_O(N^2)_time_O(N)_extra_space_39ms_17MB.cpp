class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int validTriplets = 0;
        for(int i = 0; i < N; ++i){
            int k = 0;
            for(int j = i + 1; j < N; ++j){
                k = max(k, j + 1);
                while(k < N && sortedNums[i] + sortedNums[j] > sortedNums[k]){
                    k += 1;
                }
                validTriplets += (k - j - 1);
            }
        }

        return validTriplets;
    }
};