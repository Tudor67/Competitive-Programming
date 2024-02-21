class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long res = -1;
        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            if(i >= 2 && prefSum > sortedNums[i]){
                res = prefSum + sortedNums[i];
            }
            prefSum += sortedNums[i];
        }

        return res;
    }
};